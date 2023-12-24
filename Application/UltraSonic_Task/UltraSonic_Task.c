/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: UltraSonic
 *
 * File Name: UltraSonic_Task.c
 *
 * Created on:  Dec 9, 2023
 *
 * Description: Source file for UltraSonic Task
 *
 * Author: Abdullah Maroof
 *         Ahmed Salah
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "UltraSonic_Task.h"

/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
static u8 CH1_index,CH2_index,CH3_index,CH4_index,CH5_index,CH6_index;

static u16 CH1_arr[Max_Num_Read],CH2_arr[Max_Num_Read],
    CH3_arr[Max_Num_Read],CH4_arr[Max_Num_Read],
    CH5_arr[Max_Num_Read],CH6_arr[Max_Num_Read];

/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/
u16 Ultra_Sonic_Read[6];
UltraSonic_State UltraSonic_state = UltraSonic_Channel_4_Read;  // Check This if it's Self Trigger or No , Edit the initial Value if it's controlled from Application

/*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/

/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/
static void channel_1_Trigger(void);
static void channel_1_Read(void);

static void channel_2_Trigger(void);
static void channel_2_Read(void);

static void channel_3_Trigger(void);
static void channel_3_Read(void);

static void channel_4_Trigger(void);
static void channel_4_Read(void);

static void channel_5_Trigger(void);
static void channel_5_Read(void);

static void channel_6_Trigger(void);
static void channel_6_Read(void);

static void Channel_1_MainFunction(void);
static void Channel_2_MainFunction(void);
static void Channel_3_MainFunction(void);
static void Channel_4_MainFunction(void);
static void Channel_5_MainFunction(void);
static void Channel_6_MainFunction(void);

/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/
static void channel_1_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER1_PORT , TRIGGER1_PIN , UltraSonic_Channel1 );
}

static void channel_1_Read(void)
{
	u8 i ;
	CH1_arr[CH1_index] = Ultrasonic_readDistance();
	CH1_index++;
	if(CH1_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[0] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[0] += CH1_arr[i];
		}

		Ultra_Sonic_Read[0] /= Max_Num_Read;
		CH1_index = 0;
	}
}

static void channel_2_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER2_PORT , TRIGGER2_PIN , UltraSonic_Channel2 );
}

static void channel_2_Read(void)
{
	u8 i ;
	CH2_arr[CH2_index] = Ultrasonic_readDistance();
	CH2_index++;

	if(CH2_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[1] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[1] += CH2_arr[i];
		}

		Ultra_Sonic_Read[1] /= Max_Num_Read;
		CH2_index = 0;
	}
}

static void channel_3_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER3_PORT , TRIGGER3_PIN , UltraSonic_Channel3 );
}

static void channel_3_Read(void)
{
	u8 i ;
	CH3_arr[CH3_index] = Ultrasonic_readDistance();
	CH3_index++;

	if(CH3_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[2] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[2] += CH3_arr[i];
		}

		Ultra_Sonic_Read[2] /= Max_Num_Read;
		CH3_index = 0;
	}
}

static void channel_4_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER4_PORT , TRIGGER4_PIN , UltraSonic_Channel4 );
}

static void channel_4_Read(void)
{
	u8 i ;
	CH4_arr[CH4_index] = Ultrasonic_readDistance();
	CH4_index++;
	if(CH4_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[3] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[3] += CH4_arr[i];
		}

		Ultra_Sonic_Read[3] /= Max_Num_Read;
		CH4_index = 0;
	}
}

static void channel_5_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER5_PORT , TRIGGER5_PIN , UltraSonic_Channel5 );
}

static void channel_5_Read(void)
{
	u8 i ;
	CH5_arr[CH5_index] = Ultrasonic_readDistance();
	CH5_index++;
	if(CH5_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[4] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[4] += CH5_arr[i];
		}

		Ultra_Sonic_Read[4] /= Max_Num_Read;
		CH5_index = 0;
	}
}

static void channel_6_Trigger(void)
{
	Ultrasonic_Trigger( TRIGGER6_PORT , TRIGGER6_PIN , UltraSonic_Channel6 );
}

static void channel_6_Read(void)
{
	u8 i ;
	CH6_arr[CH6_index] = Ultrasonic_readDistance();
	CH6_index++;
	if(CH6_index == Max_Num_Read)
	{
		Ultra_Sonic_Read[5] = 0;
		for( i = 0 ; i < Max_Num_Read ; i++)
		{
			Ultra_Sonic_Read[5] += CH6_arr[i];
		}

		Ultra_Sonic_Read[5] /= Max_Num_Read;
		CH6_index = 0;
	}
}

// delay = 4 =====> 57 cm  , delay = 5 =========>  85 cm
static void Channel_1_MainFunction(void)
{
	channel_1_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_1_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application

}
static void Channel_2_MainFunction(void)
{
	channel_2_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_2_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
}
static void Channel_3_MainFunction(void)
{
	channel_3_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_3_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
}
static void Channel_4_MainFunction(void)
{
	channel_4_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_4_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
}
static void Channel_5_MainFunction(void)
{
	channel_5_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_5_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
}
static void Channel_6_MainFunction(void)
{
	channel_6_Trigger();
	vTaskDelay(Read_Periodicity);
	channel_6_Read();
	vTaskDelay(Trigger_Periodicity);	// Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
}

/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/
void UltraSonic_Read_Task( void * pvParameters )
{
	//  Delay = 3 ===> equal to 42 cm , Delay = 4 ===> equal to 60 cm , Delay = 5 ===> equal to 77 cm
	for( ;; )
	{
		switch( UltraSonic_state )
		{
		case UltraSonic_Channel_1_Read:
			Channel_1_MainFunction();
			UltraSonic_state = UltraSonic_Channel_2_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		case UltraSonic_Channel_2_Read:
			Channel_2_MainFunction();
			UltraSonic_state = UltraSonic_Channel_3_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		case UltraSonic_Channel_3_Read:
			Channel_3_MainFunction();
			UltraSonic_state = UltraSonic_Channel_4_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		case UltraSonic_Channel_4_Read:
			Channel_4_MainFunction();
			UltraSonic_state = UltraSonic_Channel_5_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		case UltraSonic_Channel_5_Read:
			Channel_5_MainFunction();
			UltraSonic_state = UltraSonic_Channel_6_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		case UltraSonic_Channel_6_Read:
			Channel_6_MainFunction();
			UltraSonic_state = UltraSonic_Channel_4_Read;  // Check This if it's Self Trigger or No , Delete this line if it's controlled from Application
		break;

		}
	}
}
/*******************************************************************************
 *                      End of File: UltraSonic_Task.c                         *
 *******************************************************************************/
