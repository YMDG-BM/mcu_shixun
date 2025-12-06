#include "main.h"

void Draw_Y2K_Style(void);

void main(void){
    Led_Config();
    Beep_Config();
    Key_Config();
    Timer0_Init();
    LCD_Init();
    Draw_Y2K_Style();
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

#define COLOR_BG      0x0000 
#define COLOR_CYAN    0x07FF 
#define COLOR_MAGENTA 0xF81F 
#define COLOR_WHITE   0xFFFF 

void Draw_Y2K_Style(void)
{
    u16 cx = 35;
    u16 cy = 45;

    LCD_Fill(0, 0, 128, 160, COLOR_BG);

    Draw_Circle(cx, cy, 28, COLOR_MAGENTA); 
    Draw_Circle(cx, cy, 26, COLOR_MAGENTA); 

    Draw_Circle(cx, cy, 3, COLOR_CYAN);
    LCD_Fill(cx-1, cy-1, cx+1, cy+1, COLOR_CYAN); 

    LCD_DrawLine(cx - 32, cy, cx - 24, cy, COLOR_CYAN);
    LCD_DrawLine(cx + 24, cy, cx + 32, cy, COLOR_CYAN);
    LCD_DrawLine(cx, cy - 32, cx, cy - 24, COLOR_CYAN);
    LCD_DrawLine(cx, cy + 24, cx, cy + 32, COLOR_CYAN);

    LCD_ShowString(cx - 12, cy - 14, (const u8*)"GRP", COLOR_CYAN, COLOR_BG, 16, 0);
    LCD_ShowString(cx - 8, cy + 2, (const u8*)"15", COLOR_WHITE, COLOR_BG, 16, 0);

    LCD_DrawLine(cx + 28, cy - 10, 128, cy - 10, COLOR_CYAN);
    LCD_DrawLine(cx + 28, cy, 100, cy, COLOR_CYAN);
    LCD_DrawLine(100, cy, 100, 80, COLOR_CYAN);

    LCD_DrawRectangle(5, 80, 123, 155, COLOR_CYAN);
    LCD_Fill(5, 80, 123, 100, COLOR_CYAN);
    LCD_ShowString(10, 82, (const u8*)"// USER_DATA", COLOR_BG, COLOR_CYAN, 16, 0);

    LCD_ShowString(15, 110, (const u8*)"Name:", COLOR_MAGENTA, COLOR_BG, 16, 0);
    LCD_ShowString(60, 110, (const u8*)"SSN", COLOR_WHITE, COLOR_BG, 16, 0);

    LCD_ShowString(15, 135, (const u8*)"ID:", COLOR_MAGENTA, COLOR_BG, 16, 0);
    LCD_ShowString(45, 135, (const u8*)"241036098", COLOR_WHITE, COLOR_BG, 16, 0);

    LCD_DrawLine(5, 158, 123, 158, COLOR_MAGENTA);
    Draw_Circle(123, 158, 2, COLOR_WHITE);
}