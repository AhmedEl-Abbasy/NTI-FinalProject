/*
 * DcMotor.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Abelrahman
 */

#include "motor.h"
#include "dio.h"
//#include "pwm.h"

void DcMotor_Init(void){
	DIO_setupPinMode(PORTB_ID,PIN0, OUTPUT);
	DIO_setupPinMode(PORTB_ID,PIN1, OUTPUT);

	DIO_writePin(PORTB_ID, PIN0,LOGIC_LOW);
	DIO_writePin(PORTB_ID, PIN1,LOGIC_LOW);
}

void DcMotor_Rotate(Config_Motor * config_ptr ){

	if(config_ptr->state==on){
//		PWM_Start(config_ptr->speed);
			if(config_ptr->direction==clockwise){
				GPIO_writePin(PORTB_ID, PIN0,LOGIC_HIGH);
				GPIO_writePin(PORTB_ID, PIN1,LOGIC_LOW);

			}else if(config_ptr->direction==anticlockwise)
			{
				GPIO_writePin(PORTB_ID, PIN0,LOGIC_LOW);
				GPIO_writePin(PORTB_ID, PIN1,LOGIC_HIGH);
			}
		}
		else{

			GPIO_writePin(PORTB_ID, PIN0,LOGIC_LOW);
			GPIO_writePin(PORTB_ID, PIN1,LOGIC_LOW);
		}

}
