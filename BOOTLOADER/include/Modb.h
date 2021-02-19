#ifndef __MODB_H__
#define __MODB_H__

#define    Version             0x06//bootloader版本号
#define    Get_Version_Internal_Order 0x00
#define    Get_Version_OutSide_Order  0x01
#define    Get_ID                     0x02
#define    Erase_Flash_ALL            0x13
#define    Write_Memory               0x21
#define    Go_APP                     0x91

#define		 MAGIC_SECTOR_ADDRESS0			0x2E80	//at app zone

#define    HEAD_FIRST                      0
#define    HEAD_SECOND                     1
#define    PROTOCOL_VERSION                2
#define    FRAME_TYPE                      3
#define    LENGTH_HIGH                     4
#define    LENGTH_LOW                      5
#define    DATA_START                      6
           
#define		 FW_SINGLE_PACKET_SIZE					 256	     ///< firmware single packet size, define by mcu
           
#define		 SERIAL_PROTOCOL_VER             0x00                                            // the version of frame 
#define		 PROTOCOL_HEAD                   0x07                                            // the lcation of frame length except for tail
#define		 FIRST_FRAME_HEAD                0x55                                            // first byte of frame 
#define		 SECOND_FRAME_HEAD               0xAA                                            // second byte of frame 
           
#define    DATA_REPORT_CMD                 0x07              //mcu report DP data to bt
#define		 UPDATE_START_CMD								 0x0A							//OTA start
#define		 UPDATE_TRANS_CMD								 0x0B							//OTA transfer
           
#define    DP_TYPE_ENUM                    0x04							//enum type
#define		 DPID_OTA_RESULT								 154

void          HandShake(void);//握手
unsigned char Receive_Packet (unsigned char *Data);//接收处理命令
/////////////////////////////////////////////////////////////////////////////////////
unsigned char Receive_Packet_tuya (unsigned char *Data);//接收处理命令
unsigned char read_magic_flag(void);
void uart1_init(unsigned char th, unsigned char tl);
unsigned char get_check_sum(unsigned char *pack, unsigned short pack_len);
void response_mcu_ota_notify_event(void);
unsigned char mcu_ota_fw_request_event(void);
static void report_mcu_ota_result(unsigned char  res);
void ota_fw_data_handle(unsigned int fw_offset,char *data0, unsigned char size0);
void mcu_ota_result_report(unsigned char status);
void my_memset(void *src, unsigned short count);
void bt_uart_write_frame(unsigned char fr_cmd, unsigned short len);
unsigned short set_bt_uart_byte(unsigned short dest, unsigned char byte);
void enable_timer(unsigned char en);
void set_magic_flag(unsigned char temp);
void read_ota_struct(void);
void Delay_us(unsigned int q1);
int strcmp_barry(unsigned char *str1,unsigned char *str2);
/////////////////////////////////////////////////////////////////////////////////////
unsigned int  CRC_CalcCRC_Process(unsigned char *fucp_CheckArr,unsigned int fui_CheckLen,unsigned char *Data,bit CRC_Flag);//CRC校验
bit           LVD_Check(unsigned long TimeOut);
#endif