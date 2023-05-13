#define DEBUG_MODULE "FLY"
#include "fly_task.h"
#include "uwb_task.h"
#include "param.h"
#include "semphr.h"
#include "swarm_ranging.h"

static TaskHandle_t flyTaskHandle = NULL;
static bool flyisInit = false;
static bool takeoff = false;
static bool land = false;
static float height = 0.5;
static float s1, s2, s3;
static SemaphoreHandle_t sem;
int opentime = 0; //开机时间
int flytime = 0; //起飞时间
bool isflying = false;
// extern object_state curstate;
// extern box_trans_t curframe;
extern uint16_t MY_UWB_ADDRESS;
extern SwarmData_t *rxdata;

void flyInit(void)
{
  if(flyisInit==true)
  {
    return ;
  }
  
  sem = xSemaphoreCreateBinary();
  xTaskCreate(flyTask, "FLYTASK", 300, NULL, 0, &flyTaskHandle);
  flyisInit = true;
}


void flyTask(void *pvParameters)
{
  while(1)
  {
    if(MY_UWB_ADDRESS == 0) //leader无人机
    {
      if(isflying) //得到控制台起飞信号
      {
        if(takeoff==false)
        {
          crtpCommanderHighLevelTakeoff(height, 0.1);
          takeoff = true;
        }
        else if(flytime < 10) //第一次测距
        {
          s1 = getDistance(1) / 100.0f;
          DEBUG_PRINT("s1: %.2f \n", s1);
        }
        else if(flytime < 20) //x轴前进1m
        {
          crtpCommanderHighLevelGoTo(0.1, 0, 0, 0, 0.1, true);
        }
        else if(flytime < 30) //第二次测距
        {
          s2 = getDistance(1) / 100.0f;
          DEBUG_PRINT("s2: %.2f \n", s2);
        }
        else if(flytime < 40) //y轴前进1m
        {
          crtpCommanderHighLevelGoTo(0, 0.1, 0, 0, 0.1, true);
        }
        else if(flytime < 50) //第三次测距
        {
          s3 += getDistance(1) / 100.0f;
          DEBUG_PRINT("s3: %.2f \n", s3);
        }
        else if(flytime < 100) //行人跟踪
        {
          ;
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLand(0, 1);
          land=true;
        }
        ++flytime;
      }
    }
    else //follower无人机
    {
      if(rxdata->isflying) //得到广播起飞信号
      {
        if(takeoff==false)
        {
          crtpCommanderHighLevelTakeoff(height, 1);
          takeoff = true;
        }
        else if(flytime < 100) //跟踪
        {
          ;
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLand(0, 1);
          land=true;
        }
        ++flytime;
      }
    }
    opentime++;
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}


PARAM_GROUP_START(fly)
PARAM_ADD(PARAM_UINT8, isflying, &isflying)
PARAM_GROUP_STOP(fly)