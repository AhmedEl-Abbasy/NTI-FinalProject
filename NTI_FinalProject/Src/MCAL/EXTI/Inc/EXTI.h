/******************************************************************************
 * Module:
 *
 * File Name: EXTI.h
 *
 * Description:
 *
 * Created on: Nov 15, 2023
 *
 * Author: Ahmed El-Abbasy & Abd EL-Rahman Tolba
 *
 *******************************************************************************/
#ifndef EXTI_H_
#define EXTI_H_
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "bit_math.h"
#include "std_types.h"
#include "EXTI_reg.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/
typedef enum{
	FALLING_TRIGGER,
	RISING_TRIGGER,
	ON_CHANGE_TRIGGER
}TRIGGER_STATUS_Type;

typedef enum{
	EXTI_0,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5,
	EXTI_6,
	EXTI_7,
	EXTI_8,
	EXTI_9,
	EXTI_10,
	EXTI_11,
	EXTI_12,
	EXTI_13,
	EXTI_14,
	EXTI_15,
}EXTIxSelect_Type;

typedef struct{
	TRIGGER_STATUS_Type Trig_Stat;
	EXTIxSelect_Type EXTIxSelect;
	void(*EXTI_CallBackFunc)(void);
}EXTI_Type;

/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
STD_ReturnState EXTI_LineEnable(EXTI_Type *EXTI);
STD_ReturnState EXTI_LineDisable(EXTI_Type *EXTI);

/*******************************************************************************
 *                      End of File: exti.h                                        *
 *******************************************************************************/
#endif /* EXTI_H_ */
