/*
 * DcMotor.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abelrahman
 */

#include "motor.h"
#include "dio.h"
#include "motor_cnfg.h"
#include "pwm.h"



void DcMotor_Init(Motor_ID_t* motor ){
	DIO_setupPinMode(motor->MotorPortID,motor->MootorPin1, PIN_OUTPUT);
	DIO_setupPinMode(motor->MotorPortID,motor->MootorPin2, PIN_OUTPUT);

	DIO_writePin(motor->MotorPortID, motor->MootorPin1,LOGIC_LOW);
	DIO_writePin(motor->MotorPortID, motor->MootorPin2,LOGIC_LOW);

	DIO_setupPinMode( motor->MotorPortID_PWM ,motor->MootorPin_PWM , PIN_ALTERNATE );
	DIO_setAlternateFunction(motor->MotorPortID_PWM ,motor->MootorPin_PWM , AF1 );

	PWM_Init();
}


void DcMotor_Rotate(Motor_ID_t* motor ){
	PWM_Start(motor->MootorPin_PWM , motor->motor_id.speed );

	if(motor->motor_id.state==on){
		//		PWM_Start(config_ptr->speed);
		if(motor->motor_id.direction==clockwise){
			DIO_writePin(motor->MotorPortID, motor->MootorPin1,LOGIC_HIGH);
			DIO_writePin(motor->MotorPortID, motor->MootorPin2,LOGIC_LOW);

		}
		else if(motor->motor_id.direction==anticlockwise)
		{
			DIO_writePin(motor->MotorPortID, motor->MootorPin1,LOGIC_LOW);
			DIO_writePin(motor->MotorPortID, motor->MootorPin2,LOGIC_HIGH);
		}
	}
	else{

		DIO_writePin(motor->MotorPortID, motor->MootorPin1,LOGIC_LOW);
		DIO_writePin(motor->MotorPortID, motor->MootorPin2,LOGIC_LOW);
	}

}
