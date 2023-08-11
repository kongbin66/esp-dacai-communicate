/************************************版权申明********************************************
**                             广州大彩光电科技有限公司
**                             http://www.gz-dc.com
**-----------------------------------文件信息--------------------------------------------
** 文件名称:   ulitity.c
** 修改时间:   2018-05-18
** 文件说明:   用户MCU串口驱动函数库
** 技术支持：  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------*/
#include "mconfig.h"

extern volatile uint32 timer_tick_count;
hw_timer_t * timer = NULL;  
#define TIME_TICK_10MS 10000

/*!
 * 名    称： delay_ms
 * 功    能： 延时n毫秒
 * 入口参数： n-延时时间
 * 出口参数： 无
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
 *  \brief    定时器初始化，定时10毫秒
 */
void TimerInit(void)
{
    /* timerBegin：初始化定时器指针
         第一个参数：设置定时器0（一共有四个定时器0、1、2、3）
         第二个参数：80分频（设置APB时钟，ESP32主频80MHz），80则时间单位为1Mhz即1us，1000000us即1s。
         第三个参数：计数方式，true向上计数 false向下计数
  */
    timer = timerBegin(0, 80, true);

    /* timerAttachInterrupt：绑定定时器
         第一个参数：指向已初始化定时器的指针
         第二个参数：中断服务器函数
         第三个参数：true边沿触发，false电平触发
*/
    timerAttachInterrupt(timer, &onTimer, true);
    /* timerAlarmWrite：配置报警计数器保护值（就是设置时间）
         第一个参数：指向已初始化定时器的指针
         第二个参数：定时时间，这里为1000000us  意思为1s进入一次中断
         第三个参数：是否重载，false定时器中断触发一次  true：死循环
*/
    timerAlarmWrite(timer, 10000, true);
    /* timerAlarmEnable：启用定时器
			 第一个参数：指向已初始化定时器的指针
	*/         
  timerAlarmEnable(timer);   
}

/*!
 *  \brief    定时器中断处理函数
 */
// void Time0_Int() interrupt 1
//{
//  TH0 = (65536-TIME_TICK_10MS) /256;
//  TL0 = (65536-TIME_TICK_10MS) %256;
//
//}
/*
    中断服务函数，为使编译器将代码分配到IRAM内，中断处理程序应该具有 IRAM_ATTR 属性
*/
void IRAM_ATTR onTimer()
{
    // Serial.println('1');
    ++timer_tick_count;
}
