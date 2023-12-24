/******************************************************************************
 * Module: UltraSonic
 *
 * File Name: UltraSonic_Task.h
 *
 * Created on: Dec 9, 2023
 *
 * Description: Header File for the UltraSonic Task
 *
 * Author: Abdullah Maroof
 * 		   Ahmed Salah
 *******************************************************************************/

#ifndef APPLICATION_ULTRASONIC_TASK_ULTRASONIC_TASK_H_
#define APPLICATION_ULTRASONIC_TASK_ULTRASONIC_TASK_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "ultrasonic.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define Max_Num_Read					2

#define Read_Periodicity				4			// Fixed Time No Change
#define Trigger_Periodicity			    5		    //change

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/
typedef enum
{
	UltraSonic_Channel_1_Read,
	UltraSonic_Channel_2_Read,
	UltraSonic_Channel_3_Read,
	UltraSonic_Channel_4_Read,
	UltraSonic_Channel_5_Read,
	UltraSonic_Channel_6_Read,

}UltraSonic_State;

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

extern u16 Ultra_Sonic_Read[6];
extern UltraSonic_State UltraSonic_state;

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
void UltraSonic_Read_Task( void * pvParameters );

/*******************************************************************************
 *                      End of File: UltraSonic_Task.h                         *
 *******************************************************************************/
#endif /* APPLICATION_ULTRASONIC_TASK_ULTRASONIC_TASK_H_ */
