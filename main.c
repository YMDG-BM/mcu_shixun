#include "main.h"

void main(void){
    Led_Config();
    LCD_Init();
    MOTOR_Config();
    Beep_Config();
    Key_Config();
    TR0=0;
    LCD_ShowString(0,128,"Cooking up a",WHITE,BLACK,16,0);
    LCD_ShowString(0,144,"delicious meal",WHITE,BLACK,16,0);
    LCD_Fill(0, 0, 128, 160, WHITE);
    LCD_ShowPicture(0, 0, 128, 128, gImage_test);
    Timer0_Init();
    Motor_Front(40);
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