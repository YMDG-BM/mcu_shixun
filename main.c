#include "main.h"

void main(void){
    Led_Config();
    Beep_Config();
    Key_Config();
    Timer0_Init();
    LCD_Init();
    LCD_Fill(0,0,128,160,WHITE);
    LCD_ShowString(50,90,"Hello",BLACK,YELLOW,16,0);
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