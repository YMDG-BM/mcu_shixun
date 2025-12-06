#include "spi.h"

void SPI2_Init(void)
{

P2M1 &= ~((0x1<<0)|(0x1<<1)|(0x1<<3));
P2M0 &= ~((0x1<<0)|(0x1<<1)|(0x1<<3));

P3M1 &= ~((0x1<<5));
P3M0 &= ~((0x1<<5));

P3M1 &= ~((0x1<<4));
P3M0 |= ((0x1<<4));


P4M1 &= ~((0x1<<5));
P4M0 &= ~((0x1<<5));	

LCD_CS_CMD(1);
LCD_BL_CMD(0);
LCD_RES_CMD(1);
LCD_SCK_CMD(0);
LCD_DC_CMD(1);
}




//SPI 速度设置函数


//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
void SPI2_ReadWriteByte(u8 TxData)
{		
unsigned char i;
for(i = 0; i < 8; i++) {
LCD_SCK_CMD(0);
if(TxData & (0x80)) {
LCD_MOSI_CMD(1);
} else {
LCD_MOSI_CMD(0);
}
Delay_us(1);
TxData <<= 1;
LCD_SCK_CMD(1);  // 上升沿发送数据

Delay_us(1);
}	
LCD_SCK_CMD(0);		
}



