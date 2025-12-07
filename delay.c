#include "delay.h"



//========================================================================
// 函数: void  delay_ms(unsigned char ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
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


// 定时器0初始化函数 - 配置为10us中断
void Timer0_Init(void) {
    AUXR |= 0x80;      // 定时器0时钟为Fosc，即1T模式
    TMOD &= 0xF0;      // 清除定时器0模式位
    TMOD |= 0x01;      // 设置定时器0为模式1（16位不自动重装载）
    
    // 计算1ms定时初值
    // 对于22.1184MHz晶振: 22118400次/秒
    // 22118400 *  1ms = 22118.4 
    // 22118400 *  100us = 2211.84 = 2212
    // 22118400 *  10us =  221.184 	 	
    // 65536 - 2212 = 63323 = 0xF75B
//    TH0 = 0xF7;        // 设置定时初值高字节
//    TL0 = 0x5C;        // 设置定时初值低字节
 
    TH0 = 0xFF;        // 设置定时初值高字节
    TL0 = 0x21;        // 设置定时初值低字节	
    ET0 = 1;           // 使能定时器0中断
    TR0 = 1;           // 启动定时器0
    EA = 1;            // 打开总中断
}
unsigned int LedTask_Time[2] = {0, 50000};
unsigned int KeyTask_Time[2] = {0, 500};
unsigned int BlueTask_Time[2] = {0, 10000};
unsigned int CarMoveTask_Time[2] = {0,20000};

//——————————————————————————————————添加的电机代码————————————————————————————
sbit IA1_PWM = P0^7;
sbit IB1_PWM = P4^7;

sbit IA2_PWM = P4^3;
sbit IB2_PWM = P4^4;

sbit IA3_PWM = P0^5;
sbit IB3_PWM = P0^6;

sbit IA4_PWM = P3^6;
sbit IB4_PWM = P3^7;


int count1 = 0;

// 定时器0中断服务函数  10us触发一次
void Timer0_ISR() interrupt 1 {

    TH0 = 0xFF;        // 设置定时初值高字节
    TL0 = 0x21;        // 设置定时初值低字节
	LedTask_Time[0]++;
	KeyTask_Time[0]++;
	BlueTask_Time[0]++;
	CarMoveTask_Time[0]++;
	//——————————————————————————————————电机控制代码————————————————————————————
    count1++;
	
    if(count1 < speed_buff[1]) {
        IA1_PWM = 1;  //高电平
    } else {
        IA1_PWM = 0;  //低电平
    }			

    if(count1 < speed_buff[0]) {
        IB1_PWM = 1;  //高电平
    } else {
        IB1_PWM = 0;  //低电平
    }	

    if(count1 < speed_buff[3]) {
        IA2_PWM = 1;  //高电平
    } else {
        IA2_PWM = 0;  //低电平
    }			

    if(count1 < speed_buff[2]) {
        IB2_PWM = 1;  //高电平
    } else {
        IB2_PWM = 0;  //低电平
    }	
		
    if(count1 < speed_buff[6]) {
        IA3_PWM = 1;  //高电平
    } else {
        IA3_PWM = 0;  //低电平
    }			

    if(count1 < speed_buff[7]) {
        IB3_PWM = 1;  //高电平
    } else {
        IB3_PWM = 0;  //低电平
    }	
		
    if(count1 < speed_buff[4]) {
        IA4_PWM = 1;  //高电平
    } else {
        IA4_PWM = 0;  //低电平
    }			

    if(count1 < speed_buff[5]) {
        IB4_PWM = 1;  //高电平
    } else {
        IB4_PWM = 0;  //低电平
    }	
    
     if(count1>100)	
       count1=0;
}