#define ALLOCATE_EXTERN
#include "HC89S003F4.h"
#include "bluetooth.h"

volatile ulong Timer_Counter = 0;

volatile ulong free_timer = 0;
ulong free_s_timer = 0;
unsigned char second_flag = 0;
unsigned char upload_disable = 0;

void Flash_EraseBlock(unsigned int fui_Address); //扇区擦除
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address);
void Delay_ms(unsigned int t);
void Delay_us(unsigned int q1);
void send_data(u8 d);

void Delay_ms(unsigned int t)
{
	Timer_Counter = 0;
	while (Timer_Counter < t)
	{
		WDTC |= 0x10; //清看门狗
	}
}

void Delay_us(unsigned int q1)
{
	unsigned int j;
	for (j = 0; j < q1; j++)
	{
		;
	}
}

/***************************************************************************************
  * @说明  	系统初始化函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/
void InitSYS()
{
	/********************************系统频率初始化***************************************/

	CLKSWR = 0x51;	 //选择内部高频RC为系统时钟，内部高频RC 2分频，Fosc=16MHz
	CLKDIV = 0x01;	 //Fosc 1分频得到Fcpu，Fcpu=16MHz
	FREQ_CLK = 0x10; //IAP频率

	/**********************************低压复位初始化**************************************/

	//	BORC = 0xC0;											 //使能低压复位1.8V，带消抖使能
	//	BORDBC = 0x01;										 //消抖时间BORDBC*8TCPU+2TCPU

	/***********************************看门口初始化***************************************/
	WDTC = 0x5F;   //允许WDT复位，空闲模式下禁止WDT，选择1024分频（内部低频时钟44K）
	WDTCCR = 0X20; //0X20/44	=0.73秒						//0xFF;	 //溢出时间约6秒
				   //溢出计算时间=（WDT分频系数*（WDTCCR+1））/内部低频RC频率
}

/***************************************************************************************
  * @说明  	定时器初始化函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/
void Timer_Init()
{
	/**********************************TIM1配置初始化**************************************/
	TCON1 = 0x00; //T1定时器时钟为Fosc
	TMOD = 0x01;  //T1-16位重装载定时器/计数器,T0-16位定时器

	//Tim1计算时间 	= (65536 - 0xFACB) * (1 / (Fosc /Timer分频系数))
	//				= 1333 / (16000000 / 12)
	//				= 1 ms

	//T1定时1ms
	//反推初值 	= 65536 - ((1/1000) / (1/(Fosc / Timer分频系数)))
	//		   	= 65536 - ((1/1000) / (1/(16000000 / 12)))
	//			= 65536 - 1333
	//			= 0xFACB

	TH1 = 0xFA;
	TL1 = 0xCB;	  //T1定时1ms
	IE |= 0x08;	  //打开T1中断
	TCON |= 0x40; //使能T1

	TH0 = 0xCB;
	TL0 = 0xEB; //T0定时时间10ms

	TCON |= 0x10; //使能T0
}

/***************************************************************************************
  * @说明  	UART1初始化函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/
void UART1_Init()
{
	/**********************************UART配置初始化**************************************/
	P2M0 = P2M0 & 0xF0 | 0x08; //P20设置为推挽输出
	P0M2 = P0M2 & 0xF0 | 0x02; //P04设置为上拉输入
	P0_4 = 1;
	TXD_MAP = 0x20; //TXD映射P20
	RXD_MAP = 0x04; //RXD映射P04
	T4CON = 0x06;	//T4工作模式：UART1波特率发生器

	//波特率计算
	//波特率 = 1/16 * (T4时钟源频率 / 定时器4预分频比) / (65536 - 0xFF98)
	//       = 1/16 * ((16000000 / 1) / 104)
	//		 = 9615.38(误差0.16%)

	//波特率9600
	//反推初值 = (65536 - ((T4时钟源频率 / 定时器4预分频比) * (1 / 16)) / 波特率)
	//		   = (65536 - (16000000 * (1 / 16) / 9600))
	//		   = (65536 - 104.167)
	//         = FF98
	//0xFF98->9600
	//0xFFCC->19200
	//0xFFEF->57600

	TH4 = 0xFF;
	TL4 = 0x98;	  //波特率9600		//0xEE;				//波特率56000
	SCON2 = 0x02; //8位UART，波特率可变
	SCON = 0x10;  //允许串行接收
	IE |= 0X10;	  //使能串口中断
				  //EA = 1;							              	 //使能总中断
}

void send_data(u8 d)
{
	SBUF = d;
	while (!(SCON & 0x02))
		;
	SCON &= ~0x02;
}

/***************************************************************************************
  * @说明  	主函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/
void main()
{
	bt_protocol_init(); //mcu_sdk
	InitSYS();
	Timer_Init();
	UART1_Init();

	LVDC = 0xAA; //LVD设置2.4V,禁止中断
	LVDDBC = 0xFF; //设置消抖时间
	LVDC &= ~0x08; //清除LVD中断标志位
				   //
	EA = 1;
	Delay_ms(500);
	
	upload_disable = 0;
	mcu_network_start();
	
	//my_memset(&ota_fw_info, 0, sizeof(ota_fw_info));
	while (1)
	{
		WDTC |= 0x10; //清看门狗
		Delay_ms(2);
		bt_uart_service();
		
		if (second_flag)
		{
			second_flag = 0;
			if (upload_disable == 0)
			{
				free_s_timer++;
				mcu_dp_value_update(DPID_FREE_TIMER, free_s_timer);
			}
		}
	}
}

/***************************************************************************************
  * @说明  	T1中断服务函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/
void TIMER1_Rpt(void) interrupt TIMER1_VECTOR
{
	Timer_Counter++;
	
	if (free_timer > 2000)
	{
		free_timer = 0;
		second_flag = 1;
	}
	else
	{
		free_timer++;
	}
}

/***************************************************************************************
  * @说明  	UART1中断服务函数
  *	@参数	  无
  * @返回值 无
  * @注		  无
***************************************************************************************/

void UART1_Rpt(void) interrupt UART1_VECTOR
{
	u8 i;
	//u16 t;

	if (SCON & 0x01) //判断接收中断标志位
	{
		i = SBUF;
		uart_receive_input(i); //mcu_sdk
		SCON &= ~0x01;		   //清除接收中断标志位
		EA = 1;
	}
}

#pragma disable
void Flash_EraseBlock(unsigned int fui_Address)
{
	while (1)
	{
		LVDC &= ~0x08; //清除LVD中断标志位
		if ((LVDC & 0x08) == 0)
			break;
	}
	EA = 0;
	IAP_CMD = 0xF00F;		//Flash解锁
	IAP_ADDR = fui_Address; //写入擦除地址
	IAP_CMD = 0xD22D;		//选择操作方式， 扇区擦除
	IAP_CMD = 0xE11E;		//触发后IAP_ADDRL&IAP_ADDRH指向0xFF，同时自动锁定
							//EA=1;
}

/**
  * @说明  	写入一个字节数据到Flash里面
  *         该函数需绝对地址编译，详情请查阅IAP操作应用手册
  * @参数  	fui_Address ：FLASH地址
  *	@参数	  fucp_SaveData：写入的数据
  * @返回值 无
  * @注		  写之前必须先对操作的扇区进行擦除
  */
#pragma disable
void FLASH_WriteData(unsigned char fuc_SaveData, unsigned int fui_Address)
{
	while (1)
	{
		LVDC &= ~0x08; //清除LVD中断标志位
		if ((LVDC & 0x08) == 0)
			break;
	}
	EA = 0;
	IAP_DATA = fuc_SaveData;
	IAP_CMD = 0xF00F; //Flash解锁
	IAP_ADDR = fui_Address;
	IAP_CMD = 0xB44B; //字节编程
	IAP_CMD = 0xE11E; //触发一次操作
					  //EA=1;
}
