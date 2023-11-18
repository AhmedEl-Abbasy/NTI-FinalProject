/******************************************************************************
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header File for the ADC Driver Contains the Functions Proto Types
 *
 * Author: Abdullah Maroof
 *  
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "bit_math.h"
#include "std_types.h"
#include "adc_types.h"
#include "adc_reg.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

 
/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/

//  abdullah
void ADC1_Init(ADC_Channel_t channel);
void ADC2_Init(ADC_Channel_t channel);

// youmna
void ADC3_Init(ADC_Channel_t channel);
void ADC4_Init(ADC_Channel_t channel);



STD_ReturnState ADC_CheckStatus(ADC_t adc, ADC_Status_t Status); 
void ADC_Enable(ADC_t adc);

void  ADC_Read(ADC_t adc , u16 *Read_Ptr);
void ADC_Disable(ADC_t adc);


void ADC_Start(ADC_t adc);


 
#endif

/*******************************************************************************
 *                      End of File: .h                                        *
 *******************************************************************************/
