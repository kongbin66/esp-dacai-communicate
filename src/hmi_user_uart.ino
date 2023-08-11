/************************************��Ȩ����********************************************
**                             ���ݴ�ʹ��Ƽ����޹�˾
**                             http://www.gz-dc.com
**-----------------------------------�ļ���Ϣ--------------------------------------------
** �ļ�����:   hmi_user_uart.c
** �޸�ʱ��:   2018-05-18
** �ļ�˵��:   �û�MCU��������������
** ����֧�֣�  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------*/
#include "mconfig.h"

void UartInit()
{
    // �����趨
    SerialMon.begin(115200);
    SerialMon.printf("init_start\n");                          // ��ʼ�����Դ���
    SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX); // ��ʼ��AT����
    SerialAT.onReceive(SerialAT_callback);                      // ���ûص�����
}

// �����жϺ���
void SerialAT_callback()
{
    int i = 0;
    // while (SerialAT.available()) {
    //     SerialAT.readBytes(data, 2);
    // }
    while (SerialAT.available())
    {
        rx_buff[i] = SerialAT.read();
        queue_push(rx_buff[i]); // ѹ�뵽ָ�����
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