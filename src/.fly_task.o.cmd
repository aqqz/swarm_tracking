cmd_/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o := arm-none-eabi-gcc -Wp,-MD,/home/taozhi/project/NetSI/relative_location_demo/src/.fly_task.o.d     -I/home/taozhi/project/NetSI/relative_location_demo/src -D__firmware__ -fno-exceptions -Wall -Wmissing-braces -fno-strict-aliasing -ffunction-sections -fdata-sections -Wdouble-promotion -std=gnu11 -DCRAZYFLIE_FW   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/CMSIS/CMSIS/Core/Include   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/CMSIS/CMSIS/DSP/Include   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/libdw1000/inc   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/libdw3000/include   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include   -I/home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/portable/GCC/ARM_CM4F   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/config   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/platform/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/deck/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/deck/drivers/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/drivers/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/drivers/bosch/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/drivers/esp32/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/hal/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/kalman_core   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/lighthouse   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/cpx   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/p2pDTR   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/kve   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/lighthouse   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/tdoa   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/FatFS   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/CMSIS/STM32F4xx/Include   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/STM32_USB_Device_Library/Core/inc   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/STM32_USB_OTG_Driver/inc   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/STM32F4xx_StdPeriph_Driver/inc   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/vl53l1   -I/home/taozhi/project/NetSI/crazyflie-firmware/src/lib/vl53l1/core/inc   -I/home/taozhi/project/NetSI/relative_location_demo/build/include/generated -fno-delete-null-pointer-checks --param=allow-store-data-races=0 -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -Werror=implicit-int -Werror=date-time -DCC_HAVE_ASM_GOTO -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g3 -fno-math-errno -DARM_MATH_CM4 -D__FPU_PRESENT=1 -mfp16-format=ieee -Wno-array-bounds -Wno-stringop-overread -Wno-stringop-overflow -DSTM32F4XX -DSTM32F40_41xxx -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -Os   -c -o /home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o /home/taozhi/project/NetSI/relative_location_demo/src/fly_task.c

source_/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o := /home/taozhi/project/NetSI/relative_location_demo/src/fly_task.c

deps_/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o := \
  /home/taozhi/project/NetSI/relative_location_demo/src/fly_task.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/crtp_commander_high_level.h \
  /usr/lib/gcc/arm-none-eabi/9.2.1/include/stdbool.h \
  /usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/math3d.h \
  /usr/include/newlib/math.h \
  /usr/include/newlib/sys/reent.h \
  /usr/include/newlib/_ansi.h \
  /usr/include/newlib/newlib.h \
  /usr/include/newlib/_newlib_version.h \
  /usr/include/newlib/sys/config.h \
    $(wildcard include/config/h//.h) \
  /usr/include/newlib/machine/ieeefp.h \
  /usr/include/newlib/sys/features.h \
  /usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h \
  /usr/include/newlib/sys/_types.h \
  /usr/include/newlib/machine/_types.h \
  /usr/include/newlib/machine/_default_types.h \
  /usr/include/newlib/sys/lock.h \
  /usr/include/newlib/sys/cdefs.h \
  /usr/include/newlib/_ansi.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/stabilizer_types.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/hal/interface/imu_types.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/lighthouse/lighthouse_types.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/FreeRTOS.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/config/FreeRTOSConfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/debug/queue/monitor.h) \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/config/config.h \
    $(wildcard include/config/h/.h) \
    $(wildcard include/config/block/address.h) \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/drivers/interface/nrf24l01.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/drivers/interface/nRF24L01reg.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/config/trace.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/hal/interface/usec_time.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/cfassert.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/projdefs.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/portable.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/deprecated_definitions.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/portable/GCC/ARM_CM4F/portmacro.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/mpu_wrappers.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/task.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/list.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/debug.h \
    $(wildcard include/config/debug/print/on/uart1.h) \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/config/config.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/console.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/utils/interface/eprintf.h \
  /usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h \
  /home/taozhi/project/NetSI/relative_location_demo/src/uwb_task.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/deck/drivers/interface/adhocdeck.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/libdw3000/include/libdw3000.h \
    $(wildcard include/config/mask.h) \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/libdw3000/include/mac_802_15_4.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/libdw3000/include/dwTypes.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/queue.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/task.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/deck/drivers/interface/ranging_struct.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/deck/drivers/interface/adhocdeck.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/deck/drivers/interface/flooding_struct.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/param.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/param_logic.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/src/modules/interface/crtp.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/semphr.h \
  /home/taozhi/project/NetSI/crazyflie-firmware/vendor/FreeRTOS/include/queue.h \

/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o: $(deps_/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o)

$(deps_/home/taozhi/project/NetSI/relative_location_demo/src/fly_task.o):
