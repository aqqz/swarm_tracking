#define DEBUG_MODULE "UWB"
#include "stm32fxxx.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

#include "autoconf.h"
#include "debug.h"
#include "deck.h"
#include "estimator.h"
#include "log.h"
#include "param.h"
#include "system.h"

#include "adhocdeck.h"
#include "dwTypes.h"
#include "libdw3000.h"
#include "dw3000.h"
#include "uwb_task.h"
#include "fly_task.h"


static TaskHandle_t uwbTxTaskHandle = 0;
static TaskHandle_t uwbRxTaskHandle = 0;
static QueueHandle_t rxQueue;

uint16_t MY_UWB_ADDRESS;
UWB_Packet_t txPacketCache;
UWB_Packet_t rxPacketCache;
SwarmData_t txdata;
SwarmData_t *rxdata;
extern int opentime;
extern int flytime;
extern bool isflying;




static void uwbTxTask(void *parameters) {
  systemWaitStart();

  memset(&txPacketCache, 0, sizeof(UWB_Packet_t));
  txPacketCache.header.type = DATA;
  memset(&txdata, 0, sizeof(txdata));

  while(1)
  {
    if(MY_UWB_ADDRESS == 0)
    {
      if(opentime < 30) //广播起飞信号
      {
        txdata.ack = 0;
        txdata.isflying = isflying;
        txdata.islanding = 0;
        txdata.seqNumber++;

        txPacketCache.header.length = sizeof(Packet_Header_t) + sizeof(SwarmData_t);
        memcpy(&txPacketCache.payload, &txdata, sizeof(txdata));

        uwbSendPacketBlock(&txPacketCache);
        // DEBUG_PRINT("uav 0 send.\n");
      }

      if(flytime < 10)
      {

      }
      else if(flytime < 20)
      {

      }
    }
    else
    {

    }
    vTaskDelay(100);
  }
}

static void uwbRxTask(void *parameters) {
  systemWaitStart();
  memset(&rxPacketCache, 0, sizeof(UWB_Packet_t));

  while(1)
  {
    if(MY_UWB_ADDRESS == 0)
    {

    }
    else
    {
      if(opentime < 30)
      {
        uwbReceivePacketBlock(DATA, &rxPacketCache);
        rxdata = (SwarmData_t *)&rxPacketCache.payload;
        DEBUG_PRINT("uav 1 recv.\n");
        DEBUG_PRINT("%d %d %d %d\n", rxdata->ack, rxdata->isflying, rxdata->islanding, rxdata->seqNumber);
      }
      if(flytime < 10)
      {

      }
      else if(flytime < 20)
      {

      }
    }
    vTaskDelay(100);
  }
}

void uwbInit() {
  // 获取UWB地址
  MY_UWB_ADDRESS = getUWBAddress();
  DEBUG_PRINT("MY_UWB_ADDRESS = %d\n", MY_UWB_ADDRESS);

  // 初始化接收队列
  rxQueue = xQueueCreate(5, sizeof(UWB_Packet_t));
  
  // 初始化监听器
  UWB_Message_Listener_t listener;
  listener.type = DATA;
  listener.rxQueue = rxQueue;
  listener.rxCb = NULL;
  listener.txCb = NULL;
  
  // 注册监听器
  uwbRegisterListener(&listener);
    
  // 创建数据发送任务
  xTaskCreate(uwbTxTask, "UWB_TXTASK", 4 * configMINIMAL_STACK_SIZE, NULL,
              3, &uwbTxTaskHandle);
  // 创建数据接收任务
  xTaskCreate(uwbRxTask, "UWB_RXTASK", 4 * configMINIMAL_STACK_SIZE, NULL,
              3, &uwbRxTaskHandle);
}
