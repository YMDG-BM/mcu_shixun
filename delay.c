#include "delay.h"

void Delay1ms(void)		//@22.1184MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 22;
	j = 128;
	do
	{
		while (--j);
	} while (--i);
}

void Delay1us(void)		//@22.1184MHz
{
	unsigned char i;

	i = 3;
	while (--i);
}

void Delay_us(int time)
{
	while(time--) {
		Delay1us();
	}
}

void Delay_ms(int time)
{

	while(time--) {
        Delay1ms();
	}
}

void Timer0_Init(void) {
    AUXR |= 0x80;     
    TMOD &= 0xF0;    
    TMOD |= 0x01;     
    TH0 = 0xFF;      
    TL0 = 0x21;  
    ET0 = 1;         
    TR0 = 1;          
    EA = 1;            
}
unsigned int LedTask_Time[2] = {0, 50000};
unsigned int KeyTask_Time[2] = {0, 500};
unsigned int BlueTask_Time[2] = {0, 10000};
unsigned int CarMoveTask_Time[2] = {0,20000};


void Timer0_ISR() interrupt 1 {

    TH0 = 0xFF;       
    TL0 = 0x21;        
    LedTask_Time[0]++;
    KeyTask_Time[0]++;
    BlueTask_Time[0]++;
    CarMoveTask_Time[0]++;

}