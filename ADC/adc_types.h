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
	Channel_1 = 1,
	Channel_2,
	Channel_3,
	Channel_4,
	Channel_5,
	Channel_6,
	Channel_7,
	Channel_8,
	Channel_9,
	Channel_10,
	Channel_11,
    Channel_12,
    Channel_13,
    Channel_14,
    Channel_15,
	Channel_16

}ADC_Channel_t;

#define Temp_Channel Channel_16


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
