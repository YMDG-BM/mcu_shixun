#include "tcrt5000.h"
#include "stdio.h"
#include "led.h"
u8 TCRT = 0;
void TCRT5000_Config(void)
{
   P2M1 &= ~((0x1<<6)|(0x1<<5)|(0x1<<7));
   P2M0 &=  ~((0x1<<6)|(0x1<<5)|(0x1<<7));
	
   P0M1 &=  ~((0x1<<0)|(0x1<<1));
   P0M0 &=  ~((0x1<<0)|(0x1<<1));
}


u8 TCRT5000_GetValue(){
   TCRT = 0;
  if(TCRT5_PIN == 1)
	{
		TCRT |= 0x10;
	}
  if(TCRT4_PIN == 1)	
	{
		TCRT |= 0x08;
	}
	if(TCRT3_PIN == 1)
	{
		TCRT |= 0x04;
	}
	if(TCRT2_PIN == 1)
	{
		TCRT |= 0x02;
	}
	if(TCRT1_PIN == 1)
	{
		TCRT |= 0x01;
	}
	
	return TCRT;
}





