#include "blu.h"
#include "stdio.h"
#include "string.h"
#include "usart1.h"
#include "led.h"

u8 blueBuff[3] = {0};
u8 recvCount = 0;


//AA 55 指令
u8 BluValue = 0;
void Blue_Analysis(void)
{
	if(recvCount < 1)	goto ERROR;
//	if(blueBuff[0] != 0xAA ||  blueBuff[1] != 0x55) goto ERROR;
	if(blueBuff[0]>=0 && blueBuff[0]<=9)
		BluValue = '0' + blueBuff[0];
	if(blueBuff[0] == 0x0A) BluValue = 'U';
	if(blueBuff[0] == 0x0B) BluValue = 'D';
	if(blueBuff[0] == 0x0C) BluValue = 'L';
	if(blueBuff[0] == 0x0D) BluValue = 'R';
	if(blueBuff[0] == 0x0E) BluValue = 'O';
	ERROR:
	recvCount = 0;
	memset(blueBuff, 0, sizeof(blueBuff));
}




void Blue_Config(void)
{
	
	
//		P_SW2 &= ~0x01;	//UART2 switch to: 0: P1.0 P1.1,  1: P4.6 P4.7
//			
//      // 使能UART2中断
////	// 配置UART2工作模式
////    S2CON |= 0x10;       // 8位数据, 可变波特率, 允许接收
////    

////	S2CON &= ~(1<<7);
//    // 计算波特率重载值
//		TH2 = (u8)((65536UL - (FOSC / 4) / BAUD) / 256);
//		TL2 = (u8)((65536UL - (FOSC / 4) / BAUD) % 256);	
//	AUXR |= 0x01;		//S1 BRT Use Timer2;
//	AUXR &= ~(1<<4);	//Timer stop
//	AUXR &= ~(1<<3);	//Timer2 set As Timer
//	AUXR |=  (1<<2);	//Timer2 set as 1T mode
//	IE2  &= ~(1<<2);	//禁止中断
//	AUXR |=  (1<<4);	//Timer run enable
//    

//		
//   S2CON = 0x50;	  
//   IE2 |= 1;  
//	  EA = 1;             // 开总中断	

/***********************/
		S2CON &= ~(1<<7);	// 8位数据, 1位起始位, 1位停止位, 无校验
		IE2   |= 1;			//允许中断
		S2CON |= (1<<4);	//允许接收
		P_SW2 &= ~0x01;	
}




//串口1 发送单个字节数据
void Usart2_SendDate(u8 dat)
{
    S2BUF = dat;                // 装载数据
    while(!(S2CON & 0x02));     // 等待发送完成
    S2CON &= ~0x02;             // 清除发送完成标志
}

void usart2_rx(void)
{
		char c=0;
    while(!(S2CON & 0x01));         // 等待发送完成
//    S2CON &= ~0x01;               // 清除发送完成标志	
	  c = S2BUF;
	  Usart2_SendDate(c);
}

//串口1 发送字符串
void Usart2_SendString(char str[])
{
	u16 i = 0;//定义了一个下标
	while(str[i] != '\0') 
	{
		Usart2_SendDate(str[i]);
		i++;
	}
}

void Blue_SendCMD(char cmd[])
{
	Usart2_SendString(cmd);
}

//void Blue_SetName(char name[])
//{
////	char buff[32] = {0};
////	sprintf(buff,"AT+NAME%s\r\n", name);
////	Usart2_SendString(buff);
//}


// UART2中断服务函数 - 数据接收和保存
void UART2_ISR(void) interrupt 8
{
	u8 dat=0;
	LED2(1);
    if(S2CON & 0x01)            // 接收中断标志
    {
        S2CON &= ~0x01;         // 清除接收中断标志
//       	Usart2_SendDate(S2BUF);
	
//				// 将数据存入缓冲区
			dat = S2BUF;
				blueBuff[recvCount++] = dat;
				recvCount %= 16;
    } 
    if(S2CON & 0x02)            // 发送中断标志
    {
        S2CON &= ~0x02;         // 清除发送中断标志
    }
}



