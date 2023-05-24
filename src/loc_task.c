#define DEBUG_MODULE "RANGE"
#include "loc_task.h"
#include "fly_task.h"
#include "uwb_task.h"

static bool locisInit = false;
static TaskHandle_t locTaskHandle = NULL;

extern int flytime;
extern uint16_t MY_UWB_ADDRESS;

static void locTask(void *parameters)
{
  while(1)
  {
    if(MY_UWB_ADDRESS == 0) //leader无人机
    {

    }
    else //followr无人机
    {
    }
    vTaskDelay(10);
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