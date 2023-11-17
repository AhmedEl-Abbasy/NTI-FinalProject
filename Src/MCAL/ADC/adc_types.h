/******************************************************************************
 * Module: ADC
 *
 * File Name: adc_types.h
 *
 * Description: Header File for the ADC Driver Contains the The Types  used in the driver
 *
 * Author: Abdullah Maroof
 *  
 *******************************************************************************/

#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/

typedef enum 
{
	Channel1_1 = 1,
	Channel1_2,
	Channel1_3,
	Channel1_4,
	Channel1_5,
	Channel1_6,
	Channel1_7,
	Channel1_8,
	Channel1_9,
	Channel1_10,
	Channel1_11,
	Temp_Channel = 16
	
}ADC1_Channel_t;

typedef enum 
{
	Channel2_1 = 1,
	Channel2_2,
	Channel2_3,
	Channel2_4,
	Channel2_5,
	Channel2_6,
	Channel2_7,
	Channel2_8,
	Channel2_9,
	Channel2_10,
	Channel2_11,	
	Channel2_12,	
	Channel2_13
	
	
}ADC2_Channel_t;

typedef enum
{
	Channel3_1 = 1,
	Channel3_2,
	Channel3_3,
	Channel3_4,
	Channel3_5,
	Channel3_6,
	Channel3_7,
	Channel3_8,
	Channel3_9,
	Channel3_10,
	Channel3_11,
	Channel3_12,
	Channel3_13,
	Channel3_14,
	Channel3_15
}ADC3_Channel_t;

typedef enum
{
	Channel4_1 = 1,
	Channel4_2,
	Channel4_3,
	Channel4_4,
	Channel4_5,
	Channel4_6,
	Channel4_7,
	Channel4_8,
	Channel4_9,
	Channel4_10,
	Channel4_11,
	Channel4_12,
	Channel4_13
}ADC4_Channel_t;


typedef enum 
{
	ADC_1 = 0,
	ADC_2,
	ADC_3,
	ADC_4

}ADC_t;

typedef enum 
{
	ADRDY = 0,
	EOSMP,
	EOC,
	EOS,
	OVR,
	JEOC,
	JEOS,
	AWD1,
	AWD2,
	AWD3,
	JQOVF


}ADC_Status_t;


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

 
/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/

 
#endif

/*******************************************************************************
 *                      End of File: .h                                        *
 *******************************************************************************/
