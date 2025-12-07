#include "motor.h"



int speed_buff[8] = {0};

CarControl_Typedef car = {MAX_SPEED, CAR_DIR_STOP};
//IA4 IB4		P3.6   P3.7
//IA2 IB2		P4.3   P4.4
//IA3 IB3		P0.5   P0.6
//IA1 IB1		P0.7   P4.7
//定时器周期1ms		占空比0
void MOTOR_Config(void)
{
	
	 P0M1 &= ~((0x1<<5)|(0x1<<6)|(0x1<<7));
   P0M0 |=  ((0x1<<5)|(0x1<<6)|(0x1<<7));
	
	 P3M1 &= ~((0x1<<6)|(0x1<<7));
   P3M0 |=  ((0x1<<6)|(0x1<<7));

	 P4M1 &= ~((0x1<<3)|(0x1<<4)|(0x1<<7));
   P4M0 |=  ((0x1<<3)|(0x1<<4)|(0x1<<7));

	Car_MotorControl(car);
}






//小车切换运行状态耗电过高会复位
void Car_MotorControl(CarControl_Typedef c)
{
	if(c.speed > MAX_SPEED)	c.speed = MAX_SPEED;
	if(c.dir == CAR_DIR_STOP) {
		Motor_Stop();
	}
	else if(c.dir == CAR_DIR_FRONT) {
		Motor_Front(c.speed);
	}
	else if(c.dir == CAR_DIR_BACK) {
		Motor_Back(c.speed);
	}
	else if(c.dir == CAR_DIR_LEFT) {
		Motor_Left(c.speed);
	}
	else if(c.dir == CAR_DIR_RIGHT) {
		Motor_Right(c.speed);
	}
}


/**
  ******************************************************************************
  * 以下代码可以更加细致的控制小车电机
  ******************************************************************************
  */

//右前方电机控制
//传参如果速度 >=0 正转，否则反转
void Motor_RightFrontControl(int speed)
{
	if(speed >= 0) {
		Motor_Front_Right_F(speed);
	}
	else {
		Motor_Front_Right_B(-speed);
	}
}

//右后方电机控制
void Motor_RightBackControl(int speed)
{
	if(speed >= 0) {
		Motor_Back_Right_F(speed);
	}
	else {
		Motor_Back_Right_B(-speed);
	}
}

//左前方电机控制
void Motor_LeftFrontControl(int speed)
{
	if(speed >= 0) {
		Motor_Front_Left_F(speed);
	}
	else {
		Motor_Front_Left_B(-speed);
	}
}

//左后方电机控制
void Motor_LeftBackControl(int speed)
{
	if(speed >= 0) {
		Motor_Back_Left_F(speed);
	}
	else {
		Motor_Back_Left_B(-speed);
	}
}



