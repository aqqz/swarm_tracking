#define DEBUG_MODULE "VISION"
#include "vision_task.h"

static uint8_t recvbuf[BUFFER_SIZE];
static TaskHandle_t visionTaskHandle = NULL;
static bool visionisInit = false;

static logVarId_t idFront;
static uint16_t front; //Multi-ranger读数
static float distance; //目标深度信息
static float lastdistance; //上一次检测到目标的深度信息
static box_trans_t curframe; //检测框信息

bool isdetected = false; //是否检测到目标
object_state curstate; //目标当前状态信息


box_trans_t* uart1GetStruct(void)
{
  memset(recvbuf, 0, sizeof(recvbuf));
  int cnt = 0;
  while(cnt < BUFFER_SIZE)
  {
    uint8_t c;
    uart1GetDataWithTimeout(&c, portMAX_DELAY);
    recvbuf[cnt++] = c;
  }
  return (box_trans_t *)recvbuf;
}

void visionInit(void)
{
  if(visionisInit)
  {
    return ;
  }

  uart1Init(115200);
  idFront = logGetVarId("range", "front");
  xTaskCreate(visionTask, "VISIONTASK", 300, NULL, 3, &visionTaskHandle);
  visionisInit = true;
}


void visionTask(void *pvParameters)
{

  memset(&curstate, 0, sizeof(curstate));

  while(1)
  {
    // get bounding box info
    box_trans_t *p = uart1GetStruct();
    memcpy(&curframe, p, BUFFER_SIZE);

    // get center depth
    front = logGetUint(idFront);
    distance = front / 1000.0;

    // vision measure
    if(curframe.box_id == 2 && curframe.box_conf > 0.2)
    {
      isdetected = true;
      if(distance < 2.5)
      {
        vision_measure(&curframe, distance, &curstate);
        lastdistance = distance;
      }
      else
      {
        vision_measure(&curframe, lastdistance, &curstate);
      }
      DEBUG_PRINT("X: %.2f Y: %.2f Z: %.2f\n", curstate.x, curstate.y, curstate.z);
    }
    else
    {
      isdetected = false;
      DEBUG_PRINT("no detection result!\n");
    }

    vTaskDelay(pdMS_TO_TICKS(100));  
  }
}


float getXCenterCoord(box_trans_t *res)
{
  return ((res->box_trans_info[0] + res->box_trans_info[2]) / 2 - IMG_W / 2);
}

float getYCenterCoord(box_trans_t *res)
{
  return ((res->box_trans_info[1] + res->box_trans_info[3]) / 2 - IMG_H / 2);
}


void vision_measure(box_trans_t *frame, float d, object_state *state)
{

  // compute bounding box center point bias 
  float x_offset = -getXCenterCoord(frame);
  float y_offset = -getYCenterCoord(frame);

  // compute object relative position
  state->x = d;
  state->y = x_offset / FOCUS_X * d;
  state->z = y_offset / FOCUS_Y * d;
}