/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: Motor_Task.c
 *
 * Created on:  Dec 5, 2023
 *
 * Description: Source file for Motor Task
 *
 * Author:
 *
 *******************************************************************************/
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "Motor_Task.h"
/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
Motor_ID_t Motor_FR = {PORTB_ID,PIN7_ID,PIN0_ID,PORTA_ID,PIN0_ID,{off,clockwise,50}};			//
Motor_ID_t Motor_BR = {PORTB_ID,PIN3_ID,PIN5_ID,PORTA_ID,PIN1_ID,{off,clockwise,50}};			//
Motor_ID_t Motor_FL = {PORTB_ID,PIN1_ID,PIN2_ID,PORTA_ID,PIN9_ID,{off,clockwise,50}};
Motor_ID_t Motor_BL = {PORTB_ID,PIN4_ID,PIN6_ID,PORTA_ID,PIN10_ID,{off,clockwise,50}};

u8 PWM_SPEED = 50;
/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/
Motor_mode_t Motor_mode =Motor_init_mode;
 /*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/

/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/
static void		Motor_init			(void);
static void 	Motor_GoForward		(void);
static void 	Motor_GoBackward	(void);
static void 	Motor_GoRight		(void);
static void 	Motor_GoLeft		(void);
static void 	Motor_GoBackRight	(void);
static void 	Motor_GoBackLeft	(void);
static void 	Motor_stop			(void);
/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/
static void		Motor_init			(void)
{
	DcMotor_Init(&Motor_FR);
	DcMotor_Init(&Motor_FL);
	DcMotor_Init(&Motor_BR);
	DcMotor_Init(&Motor_BL);
}
static void 	Motor_GoForward		(void)
{
	Motor_FR.motor_id.direction = clockwise;
	Motor_FR.motor_id.state = on ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = clockwise;
	Motor_FL.motor_id.state = on ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = clockwise;
	Motor_BR.motor_id.state = on ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = clockwise;
	Motor_BL.motor_id.state = on ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_GoBackward	(void)
{
	Motor_FR.motor_id.direction = anticlockwise;
	Motor_FR.motor_id.state = on ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = anticlockwise;
	Motor_FL.motor_id.state = on ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = anticlockwise;
	Motor_BR.motor_id.state = on ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = anticlockwise;
	Motor_BL.motor_id.state = on ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_GoRight		(void)
{
	Motor_FR.motor_id.direction = clockwise;
	Motor_FR.motor_id.state = off ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = clockwise;
	Motor_FL.motor_id.state = on ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = clockwise;
	Motor_BR.motor_id.state = off ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = clockwise;
	Motor_BL.motor_id.state = on ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_GoLeft		(void)
{
	Motor_FR.motor_id.direction = clockwise;
	Motor_FR.motor_id.state = on ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = clockwise;
	Motor_FL.motor_id.state = off ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = clockwise;
	Motor_BR.motor_id.state = on ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = clockwise;
	Motor_BL.motor_id.state = off ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_GoBackRight	(void)
{
	Motor_FR.motor_id.direction = anticlockwise;
	Motor_FR.motor_id.state = off ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = anticlockwise;
	Motor_FL.motor_id.state = on ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = anticlockwise;
	Motor_BR.motor_id.state = off ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = anticlockwise;
	Motor_BL.motor_id.state = on ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_GoBackLeft	(void)
{
	Motor_FR.motor_id.direction = anticlockwise;
	Motor_FR.motor_id.state = on ;
	Motor_FR.motor_id.speed = PWM_SPEED;

	Motor_FL.motor_id.direction = anticlockwise;
	Motor_FL.motor_id.state = off ;
	Motor_FL.motor_id.speed = PWM_SPEED;

	Motor_BR.motor_id.direction = anticlockwise;
	Motor_BR.motor_id.state = on ;
	Motor_BR.motor_id.speed = PWM_SPEED;

	Motor_BL.motor_id.direction = anticlockwise;
	Motor_BL.motor_id.state = off ;
	Motor_BL.motor_id.speed = PWM_SPEED;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}
static void 	Motor_stop			(void)
{
	Motor_FR.motor_id.state = off ;

	Motor_FL.motor_id.state = off ;

	Motor_BR.motor_id.state = off ;

	Motor_BL.motor_id.state = off ;

	DcMotor_Rotate( &Motor_FR );
	DcMotor_Rotate( &Motor_FL );
	DcMotor_Rotate( &Motor_BR );
	DcMotor_Rotate( &Motor_BL );
}

/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/

void Motor_Task(void * pvparam)
{
	 portTickType Freq = 5;
	 portTickType Start = xTaskGetTickCount();
	while(1)
	{
		switch(Motor_mode)
		{
		case Motor_init_mode:
		{
			Motor_init();
			Motor_mode = Motor_GoForward_mode;
		}
		break;
		case Motor_GoForward_mode:
		{
			Motor_GoForward();
		}
		break;
		case Motor_GoBackward_mode:
		{
			Motor_GoBackward();
		}
		break;
		case Motor_GoRight_mode:
		{
			Motor_GoRight();
		}
		break;
		case Motor_GoLeft_mode:
		{
			Motor_GoLeft();
		}
		break;
		case Motor_GoBackRight_mode:
		{
			Motor_GoBackRight();
		}
		break;
		case Motor_GoBackLeft_mode:
		{
			Motor_GoBackLeft();
		}
		break;
		case Motor_stop_mode:
		{
			Motor_stop();
		}
		break;
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
/*******************************************************************************
 *                      End of File: Motor_Task.c                              *
 *******************************************************************************/
