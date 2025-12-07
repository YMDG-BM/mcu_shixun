#include "usart1.h"




void USART1_Config(void)
{
	//选择串口
	P_SW1 &= 0x3F;      // 清除UART1切换位，确保使用P3.0/RXD和P3.1/TXD
	P_SW1 |= 0x00;
	
//	P_SW1 &= 0x3F;      // 清除UART1切换位，确保使用P3.0/RXD和P3.1/TXD
//	P_SW1 |= 0x80;	
    //配置波特率---9600
	  SCON = (SCON & 0x3f) | 0x40;        // 8位数据,可变波特率
	//配置定时器---置1选择定时器2作为波特率发生器
	AUXR |= 0x01;		//S1 BRT Use Timer2;
	AUXR &= ~(1<<4);	//Timer stop---先关闭不允许运行
	AUXR &= ~(1<<3);	//Timer2 set As Timer---对内部时钟进行计数
	AUXR |=  (1<<2);	//Timer2 set as 1T mode---串口速度控制位---不分频
	IE2  &= ~(1<<2);	//禁止中断
	AUXR |=  (1<<4);	//Timer run enable---打开定时器2
    
    // 计算波特率重载值
		TH2 = (u8)((65536UL - (FOSC / 4) / BAUD) / 256);
		TL2 = (u8)((65536UL - (FOSC / 4) / BAUD) % 256);
    

    ES = 1;             // 使能串口中断
	  REN = 1;	//允许接收
    EA = 1;             // 开总中断
}


//串口1 发送单个字节数据
void Usart1_SendDate(char c)
{
    SBUF = c;           // 写入发送缓冲区
    while(!TI);         // 等待发送完成
    TI = 0;             // 清除发送完成标志
}


//串口1 发送字符串
void Usart1_SendString(char str[])
{
	int i = 0;//定义了一个下标
	while(str[i] != '\0') 
	{
		Usart1_SendDate(str[i]);
		i++;
	}
}

#include "stdio.h"
 //重定向printf函数
char putchar(char c) {
    Usart1_SendDate(c);
    return c;
}

void usart1_rx(void)
{
		char c=0;
    while(!RI);         // 等待发送完成
    TI = 0;             // 清除发送完成标志	
	  c = SBUF;
	  Usart1_SendDate(c);
}


// 串口1中断服务函数
void UART1_ISR(void) interrupt 4 {
	char c=0;
    if (RI) {           // 接收中断
        RI = 0;         // 清除接收中断标志
       c  = SBUF;  // 读取接收缓冲区
//		if(wifi.recvOver == 0) {
//			wifi.recvData[wifi.recvCount++] = c;
//			wifi.recvCount %= 5;
//		}
//		
//		if(wifi.recvCount>=5)
//		{
//			wifi.recvOver = 1;
////			WIFI_Analysis();
//		}
			
		}
        
    if (TI) {           // 发送中断
        TI = 0;         // 清除发送中断标志
    }
}


