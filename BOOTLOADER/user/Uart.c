#include "include.h"

/*************************************************************
  Function   : IAP_SerialSendByte 
  Description: 发送一个字节
  Input      : guc_Uartbuf-发送的字节      
  return     : none    
*************************************************************/
void Uart_SendByte(unsigned char guc_Uartbuf)
{  
			SCON &=~0x10;				//UART1接收使能	
			SBUF = guc_Uartbuf;         //发送8位串口数据
			while(!(SCON & 0x02));
			SCON &=~ 0x02;			    //清除发送中断标志位
			SCON |= 0x10;				//UART1接收使能
}

/*************************************************************
  Function   : Uart_SendPacket 
  Description: 发送指定长度的数据包
  Input      : guc_Uartbuf-数据包地址   Length-字节长度     
  return     : none    
*************************************************************/
void Uart_SendPacket(unsigned char *guc_Uartbuf, unsigned char Length)
{
    unsigned char i;
    i = 0;
    while (i < Length)
    {
        Uart_SendByte(guc_Uartbuf[i]);
        i++;
    }
}
/*************************************************************
  Function   : IAP_SerialGetByte 
  Description: 接收一个字节
  Input      : guc_Uartbuf-存放接收到的字节      
  return     : none     
*************************************************************/
bit Uart_GetByte(unsigned char *guc_Uartbuf)
{
	if(SCON & 0x01)						//判断接收中断标志位
	{
		SCON&=~0x01;   				      //收到数据后，清除接收标志			
		*guc_Uartbuf = SBUF;              //转存8位串口接收数据
		return SUCCESS;		
	}
	    return ERROR;	
}

/*************************************************************
  Function   : Uart_RecvByte vv   
  Description: 定时接收一个字节
  Input      : guc_Uartbuf-存放接收到的字节 TimeOut-超时时间         
  return     : none    
*************************************************************/
bit Uart_RecvByte(unsigned char *guc_Uartbuf, unsigned long TimeOut)
{
	while(TimeOut-- > 0)
	{
		WDTC |= 0x10;
		if(Uart_GetByte(guc_Uartbuf) == SUCCESS)
		{
			return SUCCESS;
		}
	}
	return ERROR;
}
