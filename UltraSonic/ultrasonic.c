#include "ultrasonic.h"

/*Global Variables*/
u16 t1,t2;
volatile u8 flag =  0;

u8 UltraSonic_Channel;

/*
 * Description: initialization Function of the Ultrasonic driver
 */
void Ultrasonic_init(void)
{

	DIO_setupPinMode( PORTA_ID , PIN5_ID , PIN_OUTPUT );
	DIO_writePin( PORTA_ID , PIN5_ID , LOGIC_LOW );


	/*****	Init all ICU Channels 1,2,3,4,5,6 *********/

	ICU_Init();

	/**********  Channel   1   *********************************/

	DIO_setupPinMode( TRIGGER1_PORT , TRIGGER1_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER1_PORT ,  TRIGGER1_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO1_PORT , ECHO1_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO1_PORT ,ECHO1_PIN , UltraSonic1_AF );

	ICU_SelectEdge(UltraSonic_Channel1, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel1 , Ultrasonic_edgeProcessing );

	/**********  Channel   2   *********************************/

	DIO_setupPinMode( TRIGGER2_PORT , TRIGGER2_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER2_PORT ,  TRIGGER2_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO2_PORT , ECHO2_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO2_PORT ,ECHO2_PIN , UltraSonic2_AF );

	ICU_SelectEdge(UltraSonic_Channel2, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel2 , Ultrasonic_edgeProcessing);

	/**********  Channel   3   *********************************/

	DIO_setupPinMode( TRIGGER3_PORT , TRIGGER3_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER3_PORT ,  TRIGGER3_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO3_PORT , ECHO3_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO3_PORT ,ECHO3_PIN , UltraSonic3_AF );


	ICU_SelectEdge(UltraSonic_Channel3, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel3 , Ultrasonic_edgeProcessing);

	/**********  Channel   4   *********************************/

	DIO_setupPinMode( TRIGGER4_PORT , TRIGGER4_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER4_PORT ,  TRIGGER4_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO4_PORT , ECHO4_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO4_PORT ,ECHO4_PIN , UltraSonic4_AF );

	ICU_SelectEdge(UltraSonic_Channel4, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel4 , Ultrasonic_edgeProcessing);

	/**********  Channel   5   *********************************/

	DIO_setupPinMode( TRIGGER5_PORT , TRIGGER5_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER5_PORT ,  TRIGGER5_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO5_PORT , ECHO5_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO5_PORT ,ECHO5_PIN , UltraSonic5_AF );

	ICU_SelectEdge(UltraSonic_Channel5, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel5 , Ultrasonic_edgeProcessing);

	/**********  Channel   6   *********************************/

	DIO_setupPinMode( TRIGGER6_PORT , TRIGGER6_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER6_PORT ,  TRIGGER6_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO6_PORT , ECHO6_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO6_PORT ,ECHO6_PIN , UltraSonic6_AF );

	ICU_SelectEdge(UltraSonic_Channel6, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel6 , Ultrasonic_edgeProcessing);

/************* Enable NVIC for Tim 8 & 1 ICU Interrupt **********************/

	NVIC_EnableIRQ(IRQn_TIM8_CC);
	NVIC_SetPriority(IRQn_TIM8_CC,0);

	NVIC_EnableIRQ(IRQn_TIM1_CC);
	NVIC_SetPriority(IRQn_TIM8_CC,0);

}


/*
 *  Description: Send the trigger pulse to the ultrasonic
 */

void Ultrasonic_Trigger(DIO_PortID port , DIO_PinID pin , u8 Channel )
{
	UltraSonic_Channel = Channel;
	ICU_Control(UltraSonic_Channel , Enable);

	DIO_writePin( port ,  pin , LOGIC_HIGH );
	sysTick_start(10);
	DIO_writePin( port ,  pin , LOGIC_LOW );

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

	ICU_Control(UltraSonic_Channel , Disable);

	return (u16) (distance);

}


void Ultrasonic_edgeProcessing(void)
{


	if( flag == 0 )
	{
		ICU_Read(UltraSonic_Channel,&t1);
		flag = 1 ;

	}
	else if( flag == 1 )
	{

		ICU_Read(UltraSonic_Channel,&t2);
		flag = 2 ;
		// DIO_togglePin( PORTA_ID , PIN5_ID );			// Internal Led
	}

}
