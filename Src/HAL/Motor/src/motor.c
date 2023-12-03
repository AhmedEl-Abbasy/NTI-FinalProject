/*
 * DcMotor.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abelrahman
 */

#include "motor.h"
#include "dio.h"
#include "motor_cnfg.h"
//#include "pwm.h"

void DcMotor_Init(void){
	DIO_setupPinMode(MotorPortID,MootorPin1, PIN_OUTPUT);
	DIO_setupPinMode(MotorPortID,MootorPin2, PIN_OUTPUT);

	DIO_writePin(MotorPortID, MootorPin1,LOGIC_LOW);
	DIO_writePin(MotorPortID, MootorPin2,LOGIC_LOW);
}

void DcMotor_Rotate(Config_Motor * config_ptr ){

	if(config_ptr->state==on){
//		PWM_Start(config_ptr->speed);
			if(config_ptr->direction==clockwise){
				DIO_writePin(MotorPortID, MootorPin1,LOGIC_HIGH);
				DIO_writePin(MotorPortID, MootorPin2,LOGIC_LOW);

			}else if(config_ptr->direction==anticlockwise)
			{
				DIO_writePin(MotorPortID, MootorPin1,LOGIC_LOW);
				DIO_writePin(MotorPortID, MootorPin2,LOGIC_HIGH);
			}
		}
		else{

			DIO_writePin(MotorPortID, MootorPin1,LOGIC_LOW);
			DIO_writePin(MotorPortID, MootorPin2,LOGIC_LOW);
		}

}
