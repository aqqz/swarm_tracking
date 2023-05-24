#ifndef __LOC_TASK_H__
#define __LOC_TASK_H__

#include "FreeRTOS.h"
#include "swarm_ranging.h"
#include "task.h"
#include "debug.h"

typedef struct {
  float gx;
  float gy;
  float gz;
} imu_t;

void locInit(void);

#endif