#ifndef __SPI_H
#define __SPI_H			  	 

#include "delay.h"
#include "STC15F2K60S2.H"

// --- ADDED TYPE DEFINITIONS HERE ---
#ifndef _DATA_TYPES_DEFINED
#define _DATA_TYPES_DEFINED
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
#endif
// -----------------------------------

#define LCD_SPI_SCK_PIN               P21                 
#define LCD_SPI_MOSI_PIN              P23                
#define LCD_CS_PIN                    P35             
#define LCD_RES_PIN                   P20             
#define LCD_DC_PIN                    P45             
#define LCD_BL_PIN                    P34            

//时钟控制
#define LCD_SCK_CMD(x)		(x)?(LCD_SPI_SCK_PIN=1):(LCD_SPI_SCK_PIN=0)
//片选控制
#define LCD_MOSI_CMD(x)		(x)?(LCD_SPI_MOSI_PIN=1):(LCD_SPI_MOSI_PIN=0)
//片选控制
#define LCD_CS_CMD(x)		(x)?(LCD_CS_PIN=1):(LCD_CS_PIN=0)
//数据和命令引脚控制
#define LCD_DC_CMD(x)		(x)?(LCD_DC_PIN=1):(LCD_DC_PIN=0)
//复位引脚控制
#define LCD_RES_CMD(x)	(x)?(LCD_RES_PIN=1):(LCD_RES_PIN=0)
//背光控制
#define LCD_BL_CMD(x)	  (x)?(LCD_BL_PIN=1):(LCD_BL_PIN=0)

void SPI2_Init(void);
void SPI2_ReadWriteByte(u8 TxData);

#endif