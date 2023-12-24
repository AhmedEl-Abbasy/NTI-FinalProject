/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: Push Button
 *
 * File Name: BUTTON.c
 *
 * Description: Source file for the Push Button driver
 *
 * Author: Ahmed Salah
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "BUTTON.h"
#include "DIO.h"
#include "BUTTON_cfg.h"

/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/


/*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/


/******************************************************************************
 * Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * Description     : Describe this service
 *
 * Sync\Async      : Synchronous
 * Reentrancy      : Non Reentrant
 * Parameters (in) : parameterName   Parameter Description
 * Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
STD_ReturnState BUTTON_init()
{
	STD_ReturnState Ret_Val = RET_OK;

	DIO_setupPinMode(BUTTON_PORT, BUTTON_PIN, PIN_INPUT);

#if (BUTTON_CONNECTION == 1)
	DIO_activateInternal(BUTTON_PORT, BUTTON_PIN, BUTTON_CONNECTION);

#elif (BUTTON_CONNECTION == 2)
	DIO_activateInternal(BUTTON_PORT, BUTTON_PIN, BUTTON_CONNECTION);
#else
	Ret_Val = RET_NOK;

#endif

	return Ret_Val;
}

/******************************************************************************
 * Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * Description     : Describe this service
 *
 * Sync\Async      : Synchronous
 * Reentrancy      : Non Reentrant
 * Parameters (in) : parameterName   Parameter Description
 * Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
STD_ReturnState BUTTON_getStatus(BUTTON_Status *status)
{
	STD_ReturnState Ret_Val = RET_OK;
	DIO_PinLevel pin_val = LOGIC_LOW;
	DIO_readPin(BUTTON_PORT, BUTTON_PIN, &pin_val);

#if (BUTTON_CONNECTION == 1)
	if(pin_val == LOGIC_LOW)
	{
		*status = PRESSED;
	}
	else
	{
		*status = RELEASED;
	}

#elif (BUTTON_CONNECTION == 2)
	if(pin_val == LOGIC_HIGH)
	{
		*status = PRESSED;
	}
	else
	{
		*status = RELEASED;
	}

#else
	Ret_Val = RET_NOK;

#endif
	return Ret_Val;
}
/*******************************************************************************
 *                      End of File: BUTTON.c                                        *
 *******************************************************************************/
