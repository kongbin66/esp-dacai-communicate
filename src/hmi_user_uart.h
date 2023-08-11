/*! 
*  \file hmi_user_uart.h
*  \brief 串口初始化及数据发送
*  \version 1.0
*  \date 2012-2018
*  \copyright 广州大彩光电科技有限公司
*/

#ifndef _USER_UART__
#define _USER_UART__

//#include <reg52.h>       //根据用户MCU进行修改

#define uchar    unsigned char
#define uint8    unsigned char
#define uint16   unsigned short int
#define uint32   unsigned long
#define int16    short int
#define int32    long

/*! 
*  \brief  初始化串口
*/
void UartInit();

/*! 
*  \brief  串口发送单个字节
*  \param  c 数据
*/
void  SendChar(uchar c);


#endif
