#ifndef __LED_H
#define __LED_H
#include "STC15F2K60S2.H"
void Led_Config(void);
void Led_Water(void);

#define LED1_PIN P15
#define LED2_PIN P12
#define LED3_PIN P55

// x=1 open; x=0; close

#define LED1(x) (x ? (LED1_PIN=0) : (LED1_PIN=1))
#define LED2(x) (x ? (LED2_PIN=0) : (LED2_PIN=1))
#define LED3(x) (x ? (LED3_PIN=0) : (LED3_PIN=1))

#endif