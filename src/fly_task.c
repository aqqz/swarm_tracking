#define DEBUG_MODULE "FLY"
#include "fly_task.h"
#include "uwb_task.h"
#include "param.h"

static TaskHandle_t flyTaskHandle = NULL;
static bool flyisInit = false;
static bool takeoff = false;
static bool land = false;
static float height = 0.5;
int flytime = 0; //起飞时间
bool isflying = false;
// extern object_state curstate;
// extern box_trans_t curframe;
extern uint16_t MY_UWB_ADDRESS;

void flyInit(void)
{
  if(flyisInit==true)
  {
    return ;
  }
  
  xTaskCreate(flyTask, "FLYTASK", 300, NULL, 0, &flyTaskHandle);
  flyisInit = true;
}


void flyTask(void *pvParameters)
{
  while(1)
  {
    if(isflying) //得到起飞信号
    {
      if(MY_UWB_ADDRESS == 0) //leader无人机
      {
        if(takeoff==false) //起飞
        {
          crtpCommanderHighLevelTakeoff(height, 0.1);
          takeoff=true;
        }
        else if(flytime == 20) //x方向前进0.5
        {
          crtpCommanderHighLevelGoTo(0.5, 0, 0, 0, 0.1, true);
        }
        else if(flytime == 40) //y方向前进0.5
        {
          crtpCommanderHighLevelGoTo(0, 0.5, 0, 0, 0.1, true);
        }
        else if(flytime == 80) //y方向后退0.5
        {
          crtpCommanderHighLevelGoTo(0, -0.5, 0, 0, 0.1, true);
        }
        else if(flytime == 100) //x方向后退0.5
        {
          crtpCommanderHighLevelGoTo(-0.5, 0, 0, 0, 0.1, true);
        }
        else if(flytime < 200) //跟踪
        {
          ;
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLand(0, 1.0);
          land = true;
        }
      }  
      else //follower无人机
      {
        if(takeoff==false) //起飞
        {
          crtpCommanderHighLevelTakeoff(height, 0.1);
          takeoff=true;
        }
        else if(flytime == 60) //x方向前进0.5
        {
          crtpCommanderHighLevelGoTo(0.5, 0, 0, 0, 0.1, true);
        }
        else if(flytime < 200) //跟踪
        {
          ;
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLand(0, 1.0);
          land=true;
        }
      }
      flytime++;
    }
    vTaskDelay(100);
  }
}


PARAM_GROUP_START(fly)
PARAM_ADD(PARAM_UINT8, isflying, &isflying)
PARAM_GROUP_STOP(fly)