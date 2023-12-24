/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: App_Task.c
 *
 * Created on:  Dec 11, 2023
 *
 * Description: Source file for App Task
 *
 * Author: 	Ahmed El-Abbasy
 * 			Ahmed Salah
 * 			Abdullah Maroof
 * 			Abdalrahman Salem
 *
 *******************************************************************************/
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "App_Task.h"
/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
static App_Mode_t App_mode = App_init_mode;
static Motion_State_t   Motion_State = Init_State;
/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/

/*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/

/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/
static void		App_init_Fun		(void);
static void		App_Search_Fun  	(void);
static void		App_Parking_Fun 	(void);
static void		App_IDLE_Fun     	(void);

/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/

/******************************************************************************
 * Syntax          : static void		App_init_Fun		(void)
 * Description     : Initialization function for the application,
 *					 transfers the application to the search mode.
 * Sync\Async      : Synchronous
 * Parameters (in) : void
 * Return value:   : void
 *******************************************************************************/
static void		App_init_Fun		(void)
{
	Motion_State = Init_State;
	PWM_SPEED = 40;
	Motor_mode = Motor_GoForward_mode;
	App_mode = App_Search_mode;
	UltraSonic_state = UltraSonic_Channel_4_Read;

}

/******************************************************************************
 * Syntax          : static void		App_Search_Fun  	(void)
 * Description     : Starts searching for the suitable parking slot,
 *					 transfers the application to the parking mode.
 * Sync\Async      : Synchronous
 * Parameters (in) : void
 * Return value:   : void
 *******************************************************************************/
static void		App_Search_Fun  	(void)
{

	PWM_SPEED = 50;
	if(Motion_State == Init_State)
	{
		UltraSonic_state = UltraSonic_Channel_4_Read;
		if(  FrontRight_Channel <= 25 && BackRight_Channel > 25  )
		{
			Motor_mode = Motor_GoForward_mode;
		}
		else if( FrontRight_Channel > 25 )
		{
			Motion_State = Search_State;
		}
	}
	if ( Motion_State == Search_State)
	{
		UltraSonic_state = UltraSonic_Channel_4_Read;

		if(  FrontRight_Channel <= 25 && BackRight_Channel > 25 )
		{
			App_mode = App_Parking_mode;
			Motor_mode = Motor_stop_mode;
			PWM_SPEED = 60; //70
			UltraSonic_state = UltraSonic_Channel_5_Read;
			Motion_State = Parking_Steer_State;
		}
	}


}

/******************************************************************************
 * Syntax          : static void		App_Parking_Fun 	(void)
 * Description     : Starts the parking function for the suitable parking slot,
 *					 transfers the application to the idle state after parking.
 * Sync\Async      : Synchronous
 * Parameters (in) : void
 * Return value:   : void
 *******************************************************************************/
static void		App_Parking_Fun 	(void)
{
	if(Motion_State == Parking_Steer_State)
	{
		vTaskDelay(500);
		Motor_mode = Motor_GoBackRight_mode;
		UltraSonic_state = UltraSonic_Channel_5_Read;

		Motion_State = Parking_Stop_State;
	}
	if(Motion_State == Parking_Stop_State)
	{
		UltraSonic_state = UltraSonic_Channel_5_Read;
		if(BackRight_Channel <= 20 )
		{
			Motor_mode = Motor_stop_mode;
			vTaskDelay(500);
			Motion_State = Parking_Backward_State;
		}
	}
	if( Motion_State == Parking_Backward_State )
	{
		  UltraSonic_state = UltraSonic_Channel_6_Read;
		if (  BackMiddle_Channel > 25  )
		{
			PWM_SPEED = 70; //70;
			Motor_mode  = Motor_GoBackward_mode;
			Motion_State = Idle_State;
		}
	}

	if( Motion_State == Idle_State )
	{
		UltraSonic_state = UltraSonic_Channel_6_Read;
		if (  BackMiddle_Channel <= 20  )
		{
			Motor_mode = Motor_stop_mode;
			App_mode = App_IDLE_mode;
		}
	}

}

/******************************************************************************
 * Syntax          : static void		App_IDLE_Fun     	(void)
 * Description     : Application goes to the idle state, i.e. car is parked.
 * 					 Switches LED on as an indication.
 * Sync\Async      : Synchronous
 * Parameters (in) : void
 * Return value:   : void
 *******************************************************************************/
static void		App_IDLE_Fun     	(void)
{
	LED_ON();
}
/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/
void App_Task(void * pvparam)
{
	portTickType Freq = 10;
	portTickType Start = xTaskGetTickCount();
	while(1)
	{
		switch(App_mode)
		{
		case App_init_mode:
		{
			App_init_Fun();
		}
		break;
		case App_Search_mode:
		{
			App_Search_Fun();
		}
		break;
		case App_Parking_mode:
		{
			App_Parking_Fun();
		}
		break;
		case App_IDLE_mode:
		{
			App_IDLE_Fun();
		}
		break;
		}
		vTaskDelayUntil(&Start,Freq);
	}
}
/*******************************************************************************
 *                      End of File: App_Task.c                                        *
 *******************************************************************************/




