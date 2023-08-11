#if !defined(CONFIG_H)
#define CONFIG_H

/***************************澶存枃浠?******************************************/

#include "hmi_user_uart.h"
#include "hmi_driver.h"
#include "cmd_queue.h"
#include "cmd_process.h"
#include "ulitity.h"
#include "stdio.h"
#include "Arduino.h"
#include "string.h"

#define TIME_100MS 10

#define FLASH_DATA_VERSION 0XAABB0000
#define FLASH_DATA_ADDR 0X00000000

// SIM800L 硬件定义
#define MODEM_TX 27 // SIM800L串口TX引脚接在GPIO27
#define MODEM_RX 26 // SIM800L串口RX引脚接在GPIO26
// 其他硬件定义//
#define SerialMon Serial // 调试串口为UART0
#define SerialAT Serial1 // AT串口为UART1
char rx_buff[255];

volatile uint32 timer_tick_count = 0; // 定时器节拍

uint8 cmd_buffer[CMD_MAX_SIZE];      // 指令缓存
static uint16 current_screen_id = 0; // 当前画面ID
static int32 Progress_Value = 0;     // 进度条测试值
static int32 test_value = 0;         // 测试值
static uint8 update_en = 0;          // 更新标记
static int32 meter_flag = 0;         // 仪表指针往返标志位
static int32 num = 0;                // 曲线采样点计数
static int sec = 1;                  // 时间秒
static int32 curves_type = 0;        // 曲线标志位  0为正弦波，1为锯齿波
static int32 second_flag = 0;        // 时间标志位
static int32 icon_flag = 0;          // 图标标志位
static uint8 Select_H;               // 滑动选择小时
static uint8 Select_M;               // 滑动选择分钟
static uint8 Last_H;                 // 上一个选择小时
static uint8 Last_M;                 // 上一个选择分钟

//void SerialAT_callback();

#endif // CONFIG_H