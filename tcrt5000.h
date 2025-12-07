#ifndef __TCRT5000_H
#define __TCRT5000_H

#include	"STC15F2K60S2.H"

#ifndef _DATA_TYPES_DEFINED
#define _DATA_TYPES_DEFINED
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
#endif

extern u8 TCRT;

#define TCRT1_PIN		P25

#define TCRT2_PIN		P26

#define TCRT3_PIN		P27

#define TCRT4_PIN		P00

#define TCRT5_PIN		P01





void TCRT5000_Config(void);
u8 TCRT5000_GetValue();
#endif
