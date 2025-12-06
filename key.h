#ifndef __KEY_H
#define __KEY_H

#include <STC15F2K60S2.H>

#define KEY1_PIN P32
#define KEY2_PIN P33

void Key_Config(void);
void Get_Key_Value(void);
char Key_Scan(void);
#endif