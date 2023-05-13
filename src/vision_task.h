#ifndef __VISION_TASK_H__
#define __VISION_TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include "uart1.h"
#include "log.h"
#include "param.h"
#include "debug.h"
#include <stdint.h>
#include <string.h>


#define BUFFER_SIZE 28
#define IMG_W       324
#define IMG_H       324
#define FOCUS_X     ( 182.9273 )
#define FOCUS_Y     ( 182.8967 )


typedef struct {
  float box_conf; //置信度
  uint8_t box_id; //目标类别
  float box_prob; //目标概率
  float box_trans_info[4]; //xmin, ymin, xmax, ymax
} box_trans_t;

typedef struct {
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
} object_state;

box_trans_t* uart1GetStruct(void);
void visionInit(void);
void visionTask(void *pvParameters);
float getXCenterCoord(box_trans_t *res);
float getYCenterCoord(box_trans_t *res);
void vision_measure(box_trans_t *frame, float d, object_state *state);
#endif