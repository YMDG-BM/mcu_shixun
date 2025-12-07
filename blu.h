#ifndef __BLU_H
#define __BLU_H

#include	"STC15F2K60S2.H"


#ifndef _DATA_TYPES_DEFINED
#define _DATA_TYPES_DEFINED
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
#endif
extern u8 BluValue;

void Blue_Config(void);
void Blue_SendCMD(char cmd[]);
void Blue_SetName(char name[]);
void Blue_Analysis(void);
void Usart2_SendString(char str[]);
void usart2_rx(void);
void usart3_rx(void);
#endif
