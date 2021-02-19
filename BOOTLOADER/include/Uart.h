#ifndef __UART_H__
#define __UART_H__

#define NAK_TIMEOUT             400000 //接收数据超时2S
#define Command_TIMEOUT         400000 //接收命令数据超时2S
#define Command_TIMEOUT_tuya    1000000//5s
#define HandShark_TIMEOUT       4000   //接收握手数据超时20MS
#define LVD_TIMEOUT             400000 //判断LVD超时200MS

#define ACK                     0X79
#define NACK                    0X1F
#define SUCCESS                 0X01
#define ERROR                   0X00
#define NACK_TIME               0X02
#define ACK_READ                0X03
#define ERROR_STATUS            0x04
#define ERROR_PID								0x05
#define ERROR_VER								0x06
#define ERROR_SUM								0x07
#define ERROR_OFFSET						0x08
#define SUCCESS_ALL							0x09



void Uart_SendByte(unsigned char guc_Uartbuf);
void Uart_SendPacket(unsigned char *guc_Uartbuf, unsigned char Length);
bit Uart_GetByte(unsigned char *guc_Uartbuf);
bit Uart_RecvByte(unsigned char *guc_Uartbuf, unsigned long TimeOut);

#endif