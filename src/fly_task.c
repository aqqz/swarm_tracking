#define DEBUG_MODULE "FLY"
#include "fly_task.h"
#include "uwb_task.h"
#include "param.h"
#include "debug.h"
#include "semphr.h"

static TaskHandle_t flyTaskHandle = NULL;
static bool flyisInit = false;
static bool takeoff = false;
static bool land = false;
static float height = 0.5;
static SemaphoreHandle_t sem;
int opentime = 0; //开机时间
int flytime = 0; //起飞时间
bool isflying = false;
// extern object_state curstate;
// extern object_state laststate;
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
        ++flytime;
        if(takeoff==false)
        {
          // crtpCommanderHighLevelTakeoff(height, 1.0);
          takeoff = true;
        }
        else if(flytime < 10)
        {
          ;
        }
        else if(land==false)
        {
          // crtpCommanderHighLevelLand(0, 1.0);
          land=true;
        }
      }
    }
    else //follower无人机
    {
      if(rxdata->isflying) //得到广播起飞信号
      {
        ++flytime;
        if(takeoff==false)
        {
          crtpCommanderHighLevelTakeoff(height, 1.0);
          takeoff = true;
        }
        else if(flytime < 10)
        {
          ;
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLand(0, 1.0);
          land=true;
        }
      }
    }
    opentime++;
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}


PARAM_GROUP_START(fly)
PARAM_ADD(PARAM_UINT8, isflying, &isflying)
PARAM_GROUP_STOP(fly)