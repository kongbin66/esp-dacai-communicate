/************************************��Ȩ����********************************************
**                             ���ݴ�ʹ��Ƽ����޹�˾
**                             http://www.gz-dc.com
**-----------------------------------�ļ���Ϣ--------------------------------------------
** �ļ�����:   ulitity.c
** �޸�ʱ��:   2018-05-18
** �ļ�˵��:   �û�MCU��������������
** ����֧�֣�  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------*/
#include "mconfig.h"

extern volatile uint32 timer_tick_count;
hw_timer_t * timer = NULL;  
#define TIME_TICK_10MS 10000

/*!
 * ��    �ƣ� delay_ms
 * ��    �ܣ� ��ʱn����
 * ��ڲ����� n-��ʱʱ��
 * ���ڲ����� ��
 */
void delay_ms(uint32 delay)
{
    uint32 tick = timer_tick_count;
    while (1)
    {
        if (timer_tick_count - tick > delay / 10)
            break;
    }
}


/*!
 *  \brief    ��ʱ����ʼ������ʱ10����
 */
void TimerInit(void)
{
    /* timerBegin����ʼ����ʱ��ָ��
         ��һ�����������ö�ʱ��0��һ�����ĸ���ʱ��0��1��2��3��
         �ڶ���������80��Ƶ������APBʱ�ӣ�ESP32��Ƶ80MHz����80��ʱ�䵥λΪ1Mhz��1us��1000000us��1s��
         ������������������ʽ��true���ϼ��� false���¼���
  */
    timer = timerBegin(0, 80, true);

    /* timerAttachInterrupt���󶨶�ʱ��
         ��һ��������ָ���ѳ�ʼ����ʱ����ָ��
         �ڶ����������жϷ���������
         ������������true���ش�����false��ƽ����
*/
    timerAttachInterrupt(timer, &onTimer, true);
    /* timerAlarmWrite�����ñ�������������ֵ����������ʱ�䣩
         ��һ��������ָ���ѳ�ʼ����ʱ����ָ��
         �ڶ�����������ʱʱ�䣬����Ϊ1000000us  ��˼Ϊ1s����һ���ж�
         �������������Ƿ����أ�false��ʱ���жϴ���һ��  true����ѭ��
*/
    timerAlarmWrite(timer, 10000, true);
    /* timerAlarmEnable�����ö�ʱ��
			 ��һ��������ָ���ѳ�ʼ����ʱ����ָ��
	*/         
  timerAlarmEnable(timer);   
}

/*!
 *  \brief    ��ʱ���жϴ�����
 */
// void Time0_Int() interrupt 1
//{
//  TH0 = (65536-TIME_TICK_10MS) /256;
//  TL0 = (65536-TIME_TICK_10MS) %256;
//
//}
/*
    �жϷ�������Ϊʹ��������������䵽IRAM�ڣ��жϴ������Ӧ�þ��� IRAM_ATTR ����
*/
void IRAM_ATTR onTimer()
{
    // Serial.println('1');
    ++timer_tick_count;
}
