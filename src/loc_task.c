#define DEBUG_MODULE "RANGE"
#include "loc_task.h"
#include "fly_task.h"
#include "uwb_task.h"
#include "log.h"
#include "string.h"

static bool locisInit = false;
static TaskHandle_t locTaskHandle = NULL;
static logVarId_t logIdStateEstimateX;
static logVarId_t logIdStateEstimateY;
static logVarId_t logIdStateEstimateZ;
imu_t pos;

extern int flytime;
extern uint16_t MY_UWB_ADDRESS;

static float getX() { return logGetFloat(logIdStateEstimateX); }
static float getY() { return logGetFloat(logIdStateEstimateY); }
static float getZ() { return logGetFloat(logIdStateEstimateZ); }

static void locTask(void *parameters)
{
  logIdStateEstimateX = logGetVarId("stateEstimate", "x");
  logIdStateEstimateY = logGetVarId("stateEstimate", "y");
  logIdStateEstimateZ = logGetVarId("stateEstimate", "z");
  memset(&pos, 0, sizeof(pos));

  while(1)
  {
    if(MY_UWB_ADDRESS == 0) //leader无人机
    {
      pos.gx = getX(); //获得机体坐标系下坐标
      pos.gy = getY();
      pos.gz = getZ();
    }
    else //followr无人机
    {
      //打印leader imu数据
      DEBUG_PRINT("[%d] 0: %.2f, %.2f, %.2f\n", flytime, pos.gx, pos.gy, pos.gz);
    }
    vTaskDelay(100);
  }
}


void locInit(void)
{
  if(locisInit)
  {
    return ;
  }

  xTaskCreate(locTask, "LOC_TASK", 300, NULL, 3, &locTaskHandle);
}