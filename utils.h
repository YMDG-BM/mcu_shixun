#ifndef DELAY_H
#define DELAY_H

#include "STC15F2K60S2.H"
#include <intrins.h>

void Delay_ms(unsigned int n);
void Delay_us(unsigned char n);
void GPIO_Init(void);

#endif