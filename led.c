#include "led.h"

void Led_Config(void){
    P1M1 &= ~((1<<5) | (1<<2));
    P1M0 |= ((1<<5) | (1<<2));

    P5M1 &= ~(1<<5);
    P5M0 |= (1<<5);

    LED1_PIN = 1; LED2_PIN = 1; LED3_PIN = 1;
}

void Led_Water(void){
    static unsigned char count = 0;
    switch(count){
        case 0:LED1(1);LED2(0);LED3(0); break;
        case 1:LED1(0);LED2(1);LED3(0); break;
        case 2:LED1(0);LED2(0);LED3(1); break;
    }
    count++;
    count %= 3;
}