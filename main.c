#include "main.h"

void main(void){
    Led_Config();
    Beep_Config();
    Key_Config();
    Timer0_Init();
    
    while (1){
        if(KeyTask_Time[0] > KeyTask_Time[1]) {
			switch(Key_Scan()) {
				case 1: BEEP(1); break;
				case 2: BEEP(0); break;
			}
			KeyTask_Time[0] = 0;
		}
    }
    
}