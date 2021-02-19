#ifndef	__FLASH_H__
#define __FLASH_H__

#define   Chip_ID   0X08

void IAR_Soft_Rst_No_Option(void);
//void IAR_Soft_Rst_Option(void);
void IAR_Clear(unsigned int clradd);
void IAR_Clear_arrang(unsigned int clradd,unsigned int len);
void IAR_Write_Byte(unsigned int add,unsigned char datt);
void IAR_Write_arrang(unsigned int add,unsigned char *datt,unsigned int len);
void IAR_Read(unsigned int add,unsigned char *buf,unsigned int len);
unsigned char Earse_Flash(void);
unsigned char  XOR_FLASH_BLANK(unsigned int Add,unsigned int Size_Flash);
void Clear_REWP(void);
bit Read_ID(void);
#endif