#include "ultrasonic.h"

/*Global Variables*/
	  u16 t1,t2;
	 volatile u8 flag = 0;



/*
 * Description: initialization Function of the Ultrasonic driver
 */
void Ultrasonic_init(void)
{



	DIO_setupPinMode( TRIGGER_PORT , TRIGGER_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER_PORT ,  TRIGGER_PIN , LOGIC_LOW );


	DIO_setupPinMode( PORTA_ID , PIN5_ID , PIN_OUTPUT ); // Internal Led
	DIO_writePin( PORTA_ID , PIN5_ID , LOGIC_LOW );


	DIO_setupPinMode( ECHO_PORT , ECHO_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO_PORT ,ECHO_PIN , AF4 );


	TIM8_ICU_Enable(channel_1);
	TIM8_ICU_SelectEdge(channel_1, Both_Edges );
	TIM8_ICU_INT_Enable(channel_1 , Ultrasonic_edgeProcessing );


	NVIC_EnableIRQ(IRQn_TIM8_CC);
	NVIC_SetPriority(IRQn_TIM8_CC,0);
}

/*
 *  Description: Send the trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void)
{

	DIO_writePin( TRIGGER_PORT ,  TRIGGER_PIN , LOGIC_HIGH );
	sysTick_start(10);
	DIO_writePin( TRIGGER_PORT ,  TRIGGER_PIN , LOGIC_LOW );



}

/*
 * Description: Does the distance measurements and return with the distance
 */
u16 Ultrasonic_readDistance(void)
{
	u16 tim ;
	u16 distance ;

	while(flag < 2 );
	if( t1 > t2)
	{
		 tim = ( 0xFFFF - t1 ) + t2 ;
	}
	else
	{
		 tim = t2 - t1 ;
	}
	distance = ( tim / 58 ) ;
	flag = 0;
	return (u16) (distance);

}

/*
 * Description: Call Back function
 */
void Ultrasonic_edgeProcessing(void)
{

	if( flag == 0 )
	{
		 TIM8_ICU_Read(channel_1,&t1);
		 flag = 1 ;


	}
	else if( flag == 1 )
	{

		 TIM8_ICU_Read(channel_1,&t2);
		 flag = 2 ;  // check

		 DIO_togglePin( PORTA_ID , PIN5_ID );			// Internal Led


	}

}




