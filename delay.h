#ifndef DELAY_H
#define DELAY_H

#include "STC15F2K60S2.h"
#include <intrins.h>

extern unsigned int LedTask_Time[2];
extern unsigned int KeyTask_Time[2];
extern unsigned int BlueTask_Time[2];
extern unsigned int CarMoveTask_Time[2];

void Delay_ms(int time);
void Delay_us(int time);
void Delay1ms(void);
void Delay1us(void);
void Timer0_Init(void);

#endif