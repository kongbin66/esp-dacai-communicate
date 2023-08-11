#if !defined(CONFIG_H)
#define CONFIG_H

/***************************头文�?******************************************/

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

// SIM800L Ӳ������
#define MODEM_TX 27 // SIM800L����TX���Ž���GPIO27
#define MODEM_RX 26 // SIM800L����RX���Ž���GPIO26
// ����Ӳ������//
#define SerialMon Serial // ���Դ���ΪUART0
#define SerialAT Serial1 // AT����ΪUART1
char rx_buff[255];

volatile uint32 timer_tick_count = 0; // ��ʱ������

uint8 cmd_buffer[CMD_MAX_SIZE];      // ָ���
static uint16 current_screen_id = 0; // ��ǰ����ID
static int32 Progress_Value = 0;     // ����������ֵ
static int32 test_value = 0;         // ����ֵ
static uint8 update_en = 0;          // ���±��
static int32 meter_flag = 0;         // �Ǳ�ָ��������־λ
static int32 num = 0;                // ���߲��������
static int sec = 1;                  // ʱ����
static int32 curves_type = 0;        // ���߱�־λ  0Ϊ���Ҳ���1Ϊ��ݲ�
static int32 second_flag = 0;        // ʱ���־λ
static int32 icon_flag = 0;          // ͼ���־λ
static uint8 Select_H;               // ����ѡ��Сʱ
static uint8 Select_M;               // ����ѡ�����
static uint8 Last_H;                 // ��һ��ѡ��Сʱ
static uint8 Last_M;                 // ��һ��ѡ�����

//void SerialAT_callback();

#endif // CONFIG_H