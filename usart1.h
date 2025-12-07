#ifndef __USART1_H
#define __USART1_H

#include	"STC15F2K60S2.H"
#include "stdio.h"

#ifndef _DATA_TYPES_DEFINED
#define _DATA_TYPES_DEFINED
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
#endif

#define FOSC 22118400L  // 系统时钟频率
#define BAUD 9600       // 串口波特率
void USART1_Config(void);
void Usart1_SendDate(char c);
void Usart1_SendString(char str[]);
void usart1_rx(void);
#endif
