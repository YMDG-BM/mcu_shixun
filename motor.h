#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "STC15F2K60S2.h"
#include "delay.h"


#ifndef _DATA_TYPES_DEFINED
#define _DATA_TYPES_DEFINED
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
#endif

#define MAX_SPEED	90

//方向定义
typedef enum{
	CAR_DIR_STOP = 0,
	CAR_DIR_FRONT = 1,
	CAR_DIR_LEFT = 2,
	CAR_DIR_RIGHT = 3,
	CAR_DIR_BACK = 4,
}CarDIR_Typedef;

//小车控制结构体
typedef struct {
	u16 speed;
	CarDIR_Typedef dir;
}CarControl_Typedef;

extern CarControl_Typedef car;
extern int speed_buff[8];

/*
												A					B
	右前		IA1  IB1		  P0.7   P4.7	
	右后		IA2  IB2		  P4.3   P4.4	
	左前		IA4  IB4		  P3.6   P3.7	
	左后		IA3  IB3		  P0.5   P0.6	

*/

//右前轮-前进														A												B																		
#define Motor_Front_Right_F(speed) 	(speed_buff[0]=speed,speed_buff[1]=0)
//右前轮-后退														A												B																	
#define Motor_Front_Right_B(speed) 	(speed_buff[0]=0, speed_buff[1]=speed)

//右后轮-前进														A												B																		
#define Motor_Back_Right_F(speed) 	(speed_buff[2]=speed, speed_buff[3]=0)
//右后轮-后退														A												B																	
#define Motor_Back_Right_B(speed) 	(speed_buff[2]=0, speed_buff[3]=speed)
																						
//左前轮-前进														A												B																		
#define Motor_Front_Left_F(speed) 	(speed_buff[4]=speed, speed_buff[5]=0)
//左前轮-后退														A												B																	
#define Motor_Front_Left_B(speed) 	(speed_buff[4]=0, speed_buff[5]=speed)
//左后轮-前进														A												B																		
#define Motor_Back_Left_F(speed) 	  (speed_buff[6]=speed, speed_buff[7]=0)
//左后轮-后退														A												B																	
#define Motor_Back_Left_B(speed) 	  (speed_buff[6]=0, speed_buff[7]=speed)


//轮子停止
#define Motor_Stop()		(Motor_Front_Right_F(0), Motor_Back_Right_F(0),\
												 Motor_Front_Left_F(0), Motor_Back_Left_F(0))
												 
#define Motor_Front(speed)	(Motor_Front_Right_F(speed), Motor_Back_Right_F(speed),\
														 Motor_Back_Left_F(speed), Motor_Front_Left_F(speed))

#define Motor_Back(speed)		(Motor_Front_Right_B(speed), Motor_Back_Right_B(speed),\
														 Motor_Back_Left_B(speed), Motor_Front_Left_B(speed))
														 
#define Motor_Right(speed)	(Motor_Front_Right_B(speed), Motor_Back_Right_B(speed),\
														 Motor_Back_Left_F(speed), Motor_Front_Left_F(speed))

#define Motor_Left(speed)		(Motor_Front_Right_F(speed), Motor_Back_Right_F(speed),\
														 Motor_Back_Left_B(speed), Motor_Front_Left_B(speed))

void MOTOR_Config(void);
void Car_MotorControl(CarControl_Typedef c);


void Motor_RightFrontControl(int speed);
void Motor_RightBackControl(int speed);
void Motor_LeftFrontControl(int speed);
void Motor_LeftBackControl(int speed);


#endif