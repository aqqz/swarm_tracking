#define DEBUG_MODULE "FLY"
#include "fly_task.h"
#include "uwb_task.h"
#include "vision_task.h"
#include "param.h"

static TaskHandle_t flyTaskHandle = NULL;
static bool flyisInit = false;
static bool takeoff = false;
static bool land = false;
static float height = 1.0;
int flytime = 0; //起飞时间
bool isflying = false;
extern object_state curstate;
extern bool isdetected;
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
      if(MY_UWB_ADDRESS == 0)
      {
        if(takeoff==false) //起飞
        {
          crtpCommanderHighLevelTakeoff(height, 0.1);
          takeoff=true;
        }
        else if(flytime < 200) //跟踪
        {
          // if(isdetected) //检测到目标
          // {
          //   if(curstate.x > 0) 
          //   {
          //     DEBUG_PRINT("TIME: [%d] GOTO: (%.3f, %.3f, %.3f)\n", flytime, (curstate.x-1.0)*0.1, curstate.y*0.1, curstate.z*0.1);
          //     crtpCommanderHighLevelGoTo((curstate.x-1.0)*0.1, curstate.y*0.1, curstate.z*0.1, 0, 0.1, true);
          //   }
          // }
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLandWithVelocity(0, 0.4, false);
          land = true;
        }
      }
      else
      {
        if(takeoff==false)
        {
          crtpCommanderHighLevelTakeoff(height, 0.1);
          takeoff=true;
        }
        else if(flytime < 200)
        {
          // if(isdetected) //检测到目标
          // {
          //   if(curstate.x > 0) 
          //   {
          //     DEBUG_PRINT("TIME: [%d] GOTO: (%.3f, %.3f, %.3f)\n", flytime, (curstate.x-1.0)*0.1, curstate.y*0.1, curstate.z*0.1);
          //     crtpCommanderHighLevelGoTo((curstate.x-1.0)*0.1, curstate.y*0.1, curstate.z*0.1, 0, 0.1, true);
          //   }
          // }
        }
        else if(land==false)
        {
          crtpCommanderHighLevelLandWithVelocity(0, 0.4, false);
          land = true;
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