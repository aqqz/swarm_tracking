#define DEBUG_MODULE "RANGE"
#include "ranging_task.h"
#include "fly_task.h"
#include "uwb_task.h"

static bool rangingisInit = false;
static TaskHandle_t rangingTaskHandle = NULL;

float s1, s2, s3, s4, s5, s6, xa, ya, xb, yb;

extern int flytime;
extern uint16_t MY_UWB_ADDRESS;

static void rangingTask(void *parameters)
{
  while(1)
  {
    if(MY_UWB_ADDRESS == 0) //leader无人机
    {

    }
    else //followr无人机
    {
      if(flytime == 10) //第一次测距
      {
        s1 = 0;
        for(int i = 0; i < 10; i++)
        {
          s1 += getDistance(0) / 100.0;
        }
        s1 /= 10;
        DEBUG_PRINT("s1: %.2f\n", s1);
      }

      if(flytime == 30) //第二次测距
      {
        s2 = 0;
        for(int i = 0; i < 10; i++)
        {
          s2 += getDistance(0) / 100.0;
        }
        s2 /= 10;
        DEBUG_PRINT("s2: %.2f\n", s2);
      }

      if(flytime == 50) //第三次测距
      {
        s3 = 0;
        for(int i = 0; i < 10; i++)
        {
          s3 += getDistance(0) / 100.0;
        }
        s3 /= 10;
        DEBUG_PRINT("s3: %.2f\n", s3);
      }

      if(flytime == 70) //第四次测距
      {
        s4 = 0;
        for(int i = 0; i < 10; i++)
        {
          s4 += getDistance(0) / 100.0;
        }
        s4 /= 10;
        DEBUG_PRINT("s4: %.2f\n", s4);
      }

      if(flytime == 90) //第五次测距
      {
        s5 = 0;
        for(int i = 0; i < 10; i++)
        {
          s5 += getDistance(0) / 100.0;
        }
        s5 /= 10;
        DEBUG_PRINT("s5: %.2f\n", s5);
      }

      if(flytime == 110) //第六次测距
      {
        s6 = 0;
        for(int i = 0; i < 10; i++)
        {
          s6 += getDistance(0) / 100.0;
        }
        s6 /= 10;
        DEBUG_PRINT("s6: %.2f\n", s6);
      }
    }
    vTaskDelay(10);
  }
}


void rangeInit(void)
{
  if(rangingisInit)
  {
    return ;
  }

  xTaskCreate(rangingTask, "RANGING_TASK", 300, NULL, 3, &rangingTaskHandle);
}