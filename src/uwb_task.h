#ifndef __UWB_TASK_H__
#define __UWB_TASK_H__
#include "stdint.h"
#include "adhocdeck.h"


typedef struct {
  uint16_t seqNumber; //序列号
  bool isflying; //起飞标记
  bool ack; //是否响应报文
  bool islanding; //落地标记
} __attribute__((packed)) SwarmData_t;

void uwbInit();
#endif