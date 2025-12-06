#include "key.h"
#include "beep.h"
#include "delay.h"

void Key_Config() {
	P3M1 |=  ((1<<2) | (1<<3));
	P3M0 &= ~((1<<2) | (1<<3));	
}

void Get_Key_Value() {
	if(KEY1_PIN == 0) {
		Delay_ms(10);
		if(KEY1_PIN  == 0) {
			BEEP(1);
			while(KEY1_PIN == 0);
		}
	}
	if(KEY2_PIN == 0) {
		Delay_ms(10);
		if(KEY2_PIN  == 0) {
			BEEP(0);
			while(KEY2_PIN == 0);
		}
	}
}


char Key_Scan(void) {
	char KeyValue=0;
	static char KeyCount[2] = {0};

	if(KEY1_PIN == 0) {
		KeyCount[0]++;
	} else {
		if(KeyCount[0] >= 2) {
			KeyCount[0] = 0;
			KeyValue = 1;
		}
	}
	
	if(KEY2_PIN == 0) {
		KeyCount[1]++;
	} else {
		if(KeyCount[1] >= 2) {
			KeyCount[1] = 0;
			KeyValue = 2;
		}
	}
	return KeyValue;
}

