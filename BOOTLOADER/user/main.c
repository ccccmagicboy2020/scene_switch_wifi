#define ALLOCATE_EXTERN
#include "include.h"

//#define HOLYCHIP

unsigned char xdata Uart_Buf[270];//数据缓存数组 rev buffer
unsigned char xdata Uart_send_Buf[30];//send buffer
unsigned char xdata magic_flag = 0;
unsigned char xdata guc_Read_a[2] = {0x00}; //用于存放读取的数据
unsigned char guc_Read_a1[20] = {0x00}; //用于存放读取的数据
extern short ota_packet_total_num;
extern short ota_packet_current_num;
extern unsigned short led_speed;

int main(void)
{
	SystemInit();//初始化
	GPIO_Init();
	
	magic_flag = read_magic_flag();
	led_speed = 100;
	
	if (0 == magic_flag)
	{
		HandShake();//握手
		
#ifdef HOLYCHIP
		while(1)
		{
			WDTC |= 0x10;                   //清狗
			switch(Receive_Packet(Uart_Buf))//接收判断
			{
				case SUCCESS://成功发ACK   0x01
									Uart_SendByte(ACK);		//0x79
									break;
				case ERROR://失败发NACK		 0x00
									Uart_SendByte(NACK);	//0x1F
									break;
				case NACK_TIME://超时跳转APP	0x02
									IAR_Soft_Rst_No_Option();
									break;
				default://其他不操作
									break;			
			}
		}
#endif
	}
	else
	{
		enable_timer(1);
		uart1_init(0xff, 0x30);
		
		ota_packet_current_num = 0;
		ota_packet_total_num = -1;
		
		read_ota_struct();
		
		while(1)
		{
			WDTC |= 0x10;		                  //清狗
			switch(Receive_Packet_tuya(Uart_Buf))//接收判断
			{
				case SUCCESS://成功发ACK   0x01
									break;
				case ERROR://失败发NACK		 0x00
									break;
				case NACK_TIME://超时跳转APP	0x02
									if (ota_packet_current_num <= ota_packet_total_num)
									{
										mcu_ota_fw_request();
									}
									break;
				default://其他不操作
									break;			
			}			
		}		
	}
	return	0;
}

