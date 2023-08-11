/************************************版权申明********************************************
**                             广州大彩光电科技有限公司
**                             http://www.gz-dc.com
**-----------------------------------文件信息--------------------------------------------
** 文件名称:   hmi_user_uart.c
** 修改时间:   2018-05-18
** 文件说明:   用户MCU串口驱动函数库
** 技术支持：  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------*/
#include "mconfig.h"

void UartInit()
{
    // 串口设定
    SerialMon.begin(115200);
    SerialMon.printf("init_start\n");                          // 初始化调试串口
    SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX); // 初始化AT串口
    SerialAT.onReceive(SerialAT_callback);                      // 设置回调函数
}

// 串口中断函数
void SerialAT_callback()
{
    int i = 0;
    // while (SerialAT.available()) {
    //     SerialAT.readBytes(data, 2);
    // }
    while (SerialAT.available())
    {
        rx_buff[i] = SerialAT.read();
        queue_push(rx_buff[i]); // 压入到指令缓冲区
        SerialMon.write(rx_buff[i]);
        i++;
    }
}

void SendChar(uchar t)
{
    //     SBUF=t;
    //     while(TI==0);
    //     TI=0;
    SerialAT.write(t);
}