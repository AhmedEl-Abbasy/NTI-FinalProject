/******************************************************************************
 * Module:
 *
 * File Name: App_Task.h
 *
 * Created on: Dec 11, 2023
 *
 * Description: Header File for the App Task
 *
 * Author: 	Ahmed El-Abbasy
 * 			Ahmed Salah
 * 			Abdullah Maroof
 * 			Abdalrahman Salem
 *
 *******************************************************************************/
#ifndef APPLICATION_APP_TASK_APP_TASK_H_
#define APPLICATION_APP_TASK_APP_TASK_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "Header.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define FrontRight_Channel    Ultra_Sonic_Read[3] // done
#define BackRight_Channel     Ultra_Sonic_Read[4] // done

#define FrontLeft_Channel     Ultra_Sonic_Read[0] // done
#define BackLeft_Channel      Ultra_Sonic_Read[2] // done

#define FrontMiddle_Channel   Ultra_Sonic_Read[0] // done
#define BackMiddle_Channel    Ultra_Sonic_Read[5] // done


/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/
typedef enum {
	App_init_mode,
	App_Search_mode,
	App_Parking_mode,
	App_IDLE_mode
}App_Mode_t;

typedef enum {
	Init_State,
	Search_State,
	Parking_Steer_State,
	Parking_Stop_State,
	Parking_Backward_State,
	Idle_State
}Motion_State_t;
/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
void App_Task(void * pvparam);

/*******************************************************************************
 *                      End of File: App_Task.h                                     *
 *******************************************************************************/
#endif /* APPLICATION_APP_TASK_APP_TASK_H_ */
