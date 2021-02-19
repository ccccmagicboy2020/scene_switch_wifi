/*--------------------------------------------------------------------------
HC89F003.H

Header file for generic HC89F003 series microcontroller.
Copyright (c) 2009-2015 Shanghai Holychip Electronic Technology Co., Ltd.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __HC89F003_H__
#define __HC89F003_H__

/* ------------------- BYTE Register-------------------- */
/* CPU */
sfr PSW        = 0xD0;            
sfr ACC        = 0xE0;
sfr B 	       = 0xF0;
sfr SP         = 0x81;
sfr DPL        = 0x82;
sfr DPH        = 0x83;
sfr INSCON     = 0xA2;
sfr16 DPTR     = 0x82;

/* SYS CLOCK  */
sfr CLKCON     = 0x8F;	//Ê±ÖÓ¿ØÖÆ¼Ä´æÆ÷
sfr CLKSWR     = 0x8E;	//Ê±ÖÓÑ¡Ôñ¼Ä´æÆ÷

/* power  */
sfr PCON       = 0x87;

/* FLASH */
sfr IAP_ADDRL  = 0xF9;
sfr IAP_ADDRH  = 0xFA;
sfr IAP_DATA   = 0xFB;
sfr IAP_CMDL   = 0xFC;
sfr IAP_CMDH   = 0xFD;

sfr IND_ADDR   = 0x94;
sfr IND_DATA   = 0x95; 
  
sfr16 IAP_ADDR = 0xF9;
sfr16 IAP_CMD  = 0xFC;

/* REST */
sfr RSTFR      = 0xF8;

/* WDT  */
sfr WDTC       = 0xBD;

/* INTERRUPT */
sfr IE         = 0xA8;
sfr IE1        = 0xB8;
sfr IP0        = 0xA9;
sfr IP1        = 0xAA;
sfr IP2        = 0xB9;
sfr IP3        = 0xBA;

sfr16 PINTF     = 0x96;
sfr PINTF0     = 0x96;
sfr PINTF1     = 0x97;
                  
/* PORT */
sfr P0 	       = 0x80;       
sfr P1 	       = 0x90;            
sfr P2 	       = 0xA0;            

/* TIMER */
sfr TCON       = 0x88;
sfr TMOD       = 0x89;
sfr TL0        = 0x8A;
sfr TL1        = 0x8B;
sfr TH0        = 0x8C;
sfr TH1        = 0x8D;

sfr T3CON      = 0xC9;
sfr TL3        = 0xCA;
sfr TH3        = 0xCB;
sfr16 T3       = 0xCA;

sfr T4CON      = 0xCC;
sfr TL4        = 0xCD;
sfr TH4        = 0xCE;
sfr16 T4       = 0xCD;

sfr T5CON      = 0xC1;
sfr TL5        = 0xC2;
sfr TH5        = 0xC3;
sfr RCAP5L     = 0xC4;
sfr RCAP5H     = 0xC5;
sfr16 T5       = 0xC2;
sfr16 RCAP5    = 0xC4;

/* UART */
sfr SCON       = 0x98;
sfr SBUF       = 0x99;
sfr SADDR      = 0x9A;
sfr SADEN      = 0x9B;
sfr SCON2      = 0x9E;

/* SPI */
sfr SPDAT      = 0xAB;
sfr SPCTL      = 0xAC;
sfr SPSTAT     = 0xAD;

/* ADC */
sfr ADCC0      = 0xB4;
sfr ADCC1      = 0xB5;
sfr ADCRL      = 0xB6;
sfr ADCRH      = 0xB7;
sfr16 ADCR     = 0xB6;

/* CRC */
sfr CRCL       = 0xBE;
sfr CRCH       = 0xBF;
sfr16 CRCR     = 0xBE;

/* PWM */
sfr PWM0C      = 0xDA;
sfr PWM1C      = 0xDB;
sfr PWM2C      = 0xDC;
sfr PWM3C      = 0xDD;
sfr PWM3P      = 0xDE;
sfr PWM3D      = 0xDF;
sfr PWM0EN     = 0xE1;
sfr PWM0PL     = 0xE2;
sfr PWM0PH     = 0xE3;
sfr PWM0DL     = 0xE4;
sfr PWM0DH     = 0xE5;
sfr PWM0DTL    = 0xE6;
sfr PWM0DTH    = 0xE7;
sfr PWM1EN     = 0xE9;
sfr PWM1PL     = 0xEA;
sfr PWM1PH     = 0xEB;
sfr PWM1DL     = 0xEC;
sfr PWM1DH     = 0xED;
sfr PWM1DTL    = 0xEE;
sfr PWM1DTH    = 0xEF;
sfr PWM2EN     = 0xF1;
sfr PWM2PL     = 0xF2;
sfr PWM2PH     = 0xF3;
sfr PWM2DL     = 0xF4;
sfr PWM2DH     = 0xF5;
sfr PWM2DTL    = 0xF6;
sfr PWM2DTH    = 0xF7;

sfr16 PWM0P    = 0xE2;
sfr16 PWM0D    = 0xE4;
sfr16 PWM0DT   = 0xE6;
sfr16 PWM1P    = 0xEA;
sfr16 PWM1D    = 0xEC;
sfr16 PWM1DT   = 0xEE;
sfr16 PWM2P    = 0xF2;
sfr16 PWM2D    = 0xF4;
sfr16 PWM2DT   = 0xF6;

/* LVD */
sfr LVDC       = 0xBB;

/*--------------------------  BIT Register -------------------- */
/*  PSW   */
sbit CY        = PSW^7;
sbit AC        = PSW^6;
sbit F0        = PSW^5;
sbit RS1       = PSW^4;
sbit RS0       = PSW^3;
sbit OV        = PSW^2;
sbit F1        = PSW^1;
sbit P         = PSW^0;

/*  IE   */ 
sbit EA        = IE^7;
sbit ES2       = IE^6;
sbit EWDT      = IE^5;
sbit ES1       = IE^4;
sbit ET1       = IE^3;
sbit EX1       = IE^2;
sbit ET0       = IE^1;
sbit EX0       = IE^0;

/*  IE1   */ 
sbit EX8_15    = IE1^7;
sbit EX2_7     = IE1^6;
sbit EADC      = IE1^5;
sbit ET5       = IE1^4;
sbit ET4       = IE1^2;
sbit ET3       = IE1^1;
sbit ESPI      = IE1^0;

/*  RSTFR   */ 
sbit PORF      = RSTFR^7;
sbit EXRSTF    = RSTFR^6;
sbit BORF      = RSTFR^5;
sbit WDTRF     = RSTFR^4;
sbit SWRF      = RSTFR^3;
sbit SPOVF     = RSTFR^1;
sbit PLVRSTF   = RSTFR^0;

/*  SCON  */
sbit FE      = SCON^7;
sbit RXROV   = SCON^6;
sbit TXCOL   = SCON^5;
sbit REN     = SCON^4;
sbit TB8     = SCON^3;
sbit RB8     = SCON^2;
sbit TI      = SCON^1;
sbit RI      = SCON^0;

/*  TCON  */
sbit TF1       = TCON^7;
sbit TR1       = TCON^6;
sbit TF0       = TCON^5;
sbit TR0       = TCON^4;

/* P0 */
sbit P0_0      = P0^0;
sbit P0_1      = P0^1;
sbit P0_2      = P0^2;
sbit P0_3      = P0^3;
sbit P0_4      = P0^4;
sbit P0_5      = P0^5;
sbit P0_6      = P0^6;
sbit P0_7      = P0^7;

/* P1 */
sbit P1_0      = P1^0;
sbit P1_1      = P1^1;

/* P2 */
sbit P2_0      = P2^0;
sbit P2_1      = P2^1;
sbit P2_2      = P2^2;
sbit P2_3      = P2^3;
sbit P2_4      = P2^4;
sbit P2_5      = P2^5;
sbit P2_6      = P2^6;
sbit P2_7      = P2^7;

/* XSFR_TIMER */ 
#define  TCON1             (*(unsigned char volatile xdata *) 0xFE80)  // 

/* XSFR_PCA */ 
#define  T5CON1            (*(unsigned char volatile xdata *) 0xFE85)  //

/* XSFR_UART2 */ 
#define S2CON              (*(unsigned char volatile xdata *) 0xFE88)  // 
#define S2CON2             (*(unsigned char volatile xdata *) 0xFE89)  //
#define S2BUF              (*(unsigned char volatile xdata *) 0xFE8A)  //

/* XSFR_SYSCLK */ 

#define CLKDIV	           (*(unsigned char volatile xdata *) 0xFE91) 
#define FREQ_CLK           (*(unsigned char volatile xdata *) 0xFE92)  // 
#define SPOV_RSTEN         (*(unsigned char volatile xdata *) 0xFE95)  // 

/* XSFR_ADC */ 
#define ADCWC              (*(unsigned char volatile xdata *) 0xFE98)  // 
#define ADCC2              (*(unsigned char volatile xdata *) 0xFE9B)  //
 

/* XSFR_WDT */ 
#define WDTCCR             (*(unsigned char volatile xdata *) 0xFEA0)  // 

/* XSFR_CRC */ 
#define CRCC               (*(unsigned char volatile xdata *) 0xFEA2)  // 

/* XSFR_BOR */ 
#define BORC               (*(unsigned char volatile xdata *) 0xFEA4)  // 
#define BORDBC             (*(unsigned char volatile xdata *) 0xFEA5)  // 


/* XSFR_LVD */ 
#define LVDDBC             (*(unsigned char volatile xdata *) 0xFEA7)  // 

/* XSFR_RST */ 
#define RSTDBC             (*(unsigned char volatile xdata *) 0xFEAA)  // 


/* XSFR_PITS */
#define PITS               (*(unsigned long volatile xdata *) 0xFEB0)  // 
#define PITS0              (*(unsigned char volatile xdata *) 0xFEB0)  // 
#define PITS1              (*(unsigned char volatile xdata *) 0xFEB1)  // 
#define PITS2              (*(unsigned char volatile xdata *) 0xFEB2)  // 
#define PITS3              (*(unsigned char volatile xdata *) 0xFEB3)  //

#define PINTE              (*(unsigned int  volatile xdata *) 0xFEB8)
#define PINTE0             (*(unsigned char volatile xdata *) 0xFEB8)  //
#define PINTE1             (*(unsigned char volatile xdata *) 0xFEB9)  //

#define INT01_PINS         (*(unsigned char volatile xdata *) 0xFEBC)

/* XSFR_PORT */
#define PM0F			   (*(unsigned long volatile xdata *) 0xFF00)  //P0 ALL
#define P0M0               (*(unsigned char volatile xdata *) 0xFF00)  //P0[1:0] input or output set
#define P0M1               (*(unsigned char volatile xdata *) 0xFF01)  //P0[3:2] input or output set 
#define P0M2               (*(unsigned char volatile xdata *) 0xFF02)  //P0[5:4] input or output set 
#define P0M3               (*(unsigned char volatile xdata *) 0xFF03)  //P0[7:6] input or output set 

#define P0LPU              (*(unsigned char volatile xdata *) 0xFF05)  //P0[3:0] Pull up resistors input selection 

#define PM1F               (*(unsigned long volatile xdata *) 0xFF08)  //P1[1:0] input or output set
#define P1M0               (*(unsigned char volatile xdata *) 0xFF08)  //P1[1:0] input or output set

#define PM2F			   (*(unsigned long volatile xdata *) 0xFF10)  //P2 ALL
#define P2M0               (*(unsigned char volatile xdata *) 0xFF10)  //P2[1:0] input or output set
#define P2M1               (*(unsigned char volatile xdata *) 0xFF11)  //P2[3:2] input or output set 
#define P2M2               (*(unsigned char volatile xdata *) 0xFF12)  //P2[5:4] input or output set 
#define P2M3               (*(unsigned char volatile xdata *) 0xFF13)  //P2[7:6] input or output set 

#define P00DBC             (*(unsigned char volatile xdata *) 0xFF40)  //
#define P01DBC             (*(unsigned char volatile xdata *) 0xFF41)  //
#define P02DBC             (*(unsigned char volatile xdata *) 0xFF42)  //

/* XSFR_MAP */ 
#define T0_MAP             (*(unsigned char volatile xdata *) 0xFF80)  //  
#define T1_MAP             (*(unsigned char volatile xdata *) 0xFF81)  // 
#define T3_MAP             (*(unsigned char volatile xdata *) 0xFF83)  //
#define T4_MAP             (*(unsigned char volatile xdata *) 0xFF84)  // 
#define T5_MAP             (*(unsigned char volatile xdata *) 0xFF85)  // 


#define PWM0_MAP           (*(unsigned char volatile xdata *) 0xFF90)  // 
#define PWM01_MAP          (*(unsigned char volatile xdata *) 0xFF91)  // 
 
#define PWM1_MAP           (*(unsigned char volatile xdata *) 0xFF94)  // 
#define PWM11_MAP          (*(unsigned char volatile xdata *) 0xFF95)  // 

#define PWM2_MAP           (*(unsigned char volatile xdata *) 0xFF98)  //
#define PWM21_MAP          (*(unsigned char volatile xdata *) 0xFF99)  //

#define PWM3_MAP           (*(unsigned char volatile xdata *) 0xFF9C)  //

#define TXD_MAP            (*(unsigned char volatile xdata *) 0xFFA0)  //
#define RXD_MAP            (*(unsigned char volatile xdata *) 0xFFA1)  //

#define SS_MAP             (*(unsigned char volatile xdata *) 0xFFA4)  //
#define SCK_MAP            (*(unsigned char volatile xdata *) 0xFFA5)  //
#define MOSI_MAP           (*(unsigned char volatile xdata *) 0xFFA6)  //
#define MISO_MAP           (*(unsigned char volatile xdata *) 0xFFA7)  //
#define TXD2_MAP           (*(unsigned char volatile xdata *) 0xFFA8)  // 
#define RXD2_MAP           (*(unsigned char volatile xdata *) 0xFFA9)  //


/*------------------------------------------------
Interrupt Vectors:
Interrupt Address = (Number * 8) + 3
------------------------------------------------*/
#define INT0_VECTOR     0   /* 0x03 EXTERNal Interrupt 0 */
#define TIMER0_VECTOR   1   /* 0x0B Timer 0 */
#define INT1_VECTOR	    2   /* 0x13 EXTERNal Interrupt 1 */
#define TIMER1_VECTOR	3   /* 0x1B Timer 1 */
#define UART1_VECTOR	4   /* 0x23 Serial port 1 */
#define WDT_VECTOR	    5   /* 0x2B WDT */
#define LVD_VECTOR	    6   /* 0x33 LVD */
#define UART2_VECTOR	7   /* 0x3B Serial port 2 */
#define SPI_VECTOR	    8   /* 0x43 SPI */
#define T3_VECTOR	    9   /* 0x4B Timer 3 */
#define T4_VECTOR	    10  /* 0x53 Timer 4 */
#define PWM_VECTOR	    11  /* 0x5B PWM */
#define T5_VECTOR	    12  /* 0x63 Timer 5 */
#define ADC_VECTOR	    13  /* 0x6B ADC */
#define INT2_7_VECTOR	14  /* 0x73 INT2~INT7 */
#define INT8_15_VECTOR	15  /* 0x7B INT8~INT15 */


#endif/* __HC89F003_H__ */
