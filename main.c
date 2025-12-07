#include "main.h"

void FindLine(void);

void main(void){
    Led_Config();
    LCD_Init();
    Beep_Config();
    Key_Config();
    LCD_ShowString(0,128,"DashDash OTTO   ",BLACK,WHITE,16,0);
    LCD_ShowString(0,144,"Electric Car    ",BLACK,WHITE,16,0);
    LCD_ShowPicture(0, 0, 128, 128, gImage_test);
    Timer0_Init();
    MOTOR_Config();
    TCRT5000_Config();
    Motor_Front(40);
	while(1)
	{
//		LED1(1);LED2(1);LED3(1);//开灯
//		Led_Water();
////		 BEEP(1);
//		Delay_ms(500);
////		 BEEP(0);
////		Delay_ms(500);
////		LED1(0);LED2(0);LED3(0);//关灯
////		Delay_ms(500);
//		Get_Key_Value();
		//流水灯任务
		if(LedTask_Time[0]>LedTask_Time[1])
		{
			Led_Water();
			LedTask_Time[0]=0;//清零
    }
		//按键任务
		if(KeyTask_Time[0]>KeyTask_Time[1])
		{
			switch (Key_Scan())
			{
				case 1:BEEP(1);Motor_Front(40);break;
				case 2:BEEP(0);Motor_Stop();break;
      }
			KeyTask_Time[0]=0;//清零
    }
		
		//循迹任务
		if(CarMoveTask_Time[0]>CarMoveTask_Time[1])
			{
				//循迹函数
			FindLine();
			CarMoveTask_Time[0]=0;
      }
	}
}
//循迹函数
void FindLine(void)
{
	u8 TcrtValue=TCRT5000_GetValue();
	if(TcrtValue == 0x1C || TcrtValue == 0x07 ) {
		CarMoveTask_Time[1] = 60000;//直角弯的转弯时长
	}
	else CarMoveTask_Time[1] = 100;
	
	switch(TcrtValue)
		{
			case 0x1F://全黑      11111
			case 0x00://全白  停止 00000
				Motor_RightFrontControl(0);
				Motor_RightBackControl(0);
				Motor_LeftFrontControl(0);
				Motor_LeftBackControl(0);
				car.dir = CAR_DIR_STOP; 
			break;
			//左转直角弯
			case 0x1C://11100
				Motor_RightFrontControl(40);
				Motor_RightBackControl(40);
				Motor_LeftFrontControl(-20);
				Motor_LeftBackControl(-20);
				car.dir = CAR_DIR_LEFT;
			break;
			//左转大弯
			case 0x18://11000
			case 0x10://10000
				Motor_RightFrontControl(40);
				Motor_RightBackControl(40);
				Motor_LeftFrontControl(-20);
				Motor_LeftBackControl(-20);
				car.dir = CAR_DIR_LEFT;
			break;
			//左转小弯
			case 0x0C:	//01100	
			case 0x08:	//01000	
				Motor_RightFrontControl(40);
				Motor_RightBackControl(40);
				Motor_LeftFrontControl(-10);
				Motor_LeftBackControl(-10);		
				car.dir = CAR_DIR_LEFT;
			break;

			//右转直角弯
			case 0x07:	//00111
			
				Motor_RightFrontControl(-20);
				Motor_RightBackControl(-20);
				Motor_LeftFrontControl(40);
				Motor_LeftBackControl(40);
				car.dir = CAR_DIR_RIGHT;
			break;
			//右转大弯
			case 0x03://	00011
			case 0x01://	00001
				Motor_RightFrontControl(-15);
				Motor_RightBackControl(-15);
				Motor_LeftFrontControl(40);
				Motor_LeftBackControl(40);
				car.dir = CAR_DIR_RIGHT;
			break;
			//右转小弯
			case 0x06://00110
			case 0x02://00010
				Motor_RightFrontControl(-10);
				Motor_RightBackControl(-10);
				Motor_LeftFrontControl(40);
				Motor_LeftBackControl(40);
				car.dir = CAR_DIR_RIGHT;
			break;
			default: //直行
				Motor_RightFrontControl(40);
				Motor_RightBackControl(40);
				Motor_LeftFrontControl(40);
				Motor_LeftBackControl(40);
				car.dir = CAR_DIR_FRONT;
			break;	
		}
	
}
