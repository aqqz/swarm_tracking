#ifndef __FLY_TASK_H__
#define __FLY_TASK_H__

#include "crtp_commander_high_level.h"
#include "FreeRTOS.h"
#include "task.h"
#include "debug.h"
#include <math.h>
// #include "uart_task.h"
// #include "ranging_task.h"

#define PI  3.1415926

void flyInit(void);
void flyTask(void *pvParameters);



#endif