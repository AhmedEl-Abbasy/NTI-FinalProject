/******************************************************************************
 * Module:
 *
 * File Name: Header.h
 *
 * Created on: Dec 5, 2023
 *
 * Description: Header File for the Application
 *
 * Author: 	Ahmed El-Abbasy
 * 			Ahmed Salah
 * 			Abdullah Maroof
 * 			Abdalrahman Salem
 *
 *******************************************************************************/
#ifndef APPLICATION_HEADER_H_
#define APPLICATION_HEADER_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "bit_math.h"
#include "std_types.h"

//#include "NVIC.h"
//#include "dio.h"
//#include "icu.h"
//#include "TIM6.h"
//#include "dma.h"
#include "led.h"

#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#include "Motor_Task.h"
#include "UltraSonic_Task.h"
#include "App_Task.h"

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
void Sytem_Init(void);
/*******************************************************************************
 *                      End of File: Header.h                                      *
 *******************************************************************************/
#endif /* APPLICATION_HEADER_H_ */
