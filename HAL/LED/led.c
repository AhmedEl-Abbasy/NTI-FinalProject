/*
 * led.c
 *
 *  Created on: Dec 17, 2023
 *      Author: 2022
 */

#include "led.h"
#include "dio.h"

void LED_Init(void)
{
	DIO_setupPinMode( PORTA_ID , PIN5_ID , PIN_OUTPUT );
	DIO_writePin(PORTA_ID, PIN5_ID, LOGIC_LOW);
}

void LED_ON(void)
{
	DIO_writePin(PORTA_ID, PIN5_ID, LOGIC_HIGH);
}


void LED_TOGGLE(void)
{
	DIO_togglePin(PORTA_ID, PIN5_ID);
}
