#ifndef __FLY_TASK_H__
#define __FLY_TASK_H__

#include "crtp_commander_high_level.h"
#include "FreeRTOS.h"
#include "task.h"
#include "debug.h"
#include <math.h>

#define PI  3.141592653579

void flyInit(void);
void flyTask(void *pvParameters);



#endif