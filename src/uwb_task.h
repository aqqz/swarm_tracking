#ifndef __UWB_TASK_H__
#define __UWB_TASK_H__
#include "stdint.h"
#include "adhocdeck.h"

typedef struct {
  float x;
  float y;
  float z;
} waypoint_t; 

typedef struct {
  uint16_t seqNumber; //序列号
  bool isflying; //起飞标记
  bool flyack; //起飞响应
  bool isdetected; //是否检测到目标
  waypoint_t p; //设定点坐标
} __attribute__((packed)) SwarmData_t;

void uwbInit();
#endif