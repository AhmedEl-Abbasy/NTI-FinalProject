#include "ultrasonic.h"


/*Global Variables*/
static u16 t1,t2;
static u8 UltraSonic_Channel;
static u16 arr[2];

#define Read_Threshold                  50
#define UltraSonic_HW_Calibartion		58
/*
 * Description: initialization Function of the Ultrasonic driver
 */
void Ultrasonic_init(void)
{

	Channel_Config cfg = {0};
	/*****	Init all ICU Channels 1,2,3,4,5,6 *********/

	ICU_Init();

	/**********  Channel   1   *********************************/

	DIO_setupPinMode( TRIGGER1_PORT , TRIGGER1_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER1_PORT ,  TRIGGER1_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO1_PORT , ECHO1_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO1_PORT ,ECHO1_PIN , UltraSonic1_AF );

	cfg.DMA = DMA_2_;
	cfg.Chanel = CH_3_ ;
	cfg.PL = Very_High;
	cfg.MSIZE = _16_bits;
	cfg.PSIZE = _16_bits;
	cfg.MINC = TRUE;
	cfg.CIRC = TRUE;
	cfg.TCIE = TRUE;
	cfg.Block_Size = 2;
	cfg.Source_Address = (u32)(&TIM8_CCR1_REG);
	cfg.Dest_Address   = (u32)(&arr);
	cfg.EN = TRUE;
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel1, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel1 , (void*)RET_NULLPTR );

	/**********  Channel   2   *********************************/

	DIO_setupPinMode( TRIGGER2_PORT , TRIGGER2_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER2_PORT ,  TRIGGER2_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO2_PORT , ECHO2_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO2_PORT ,ECHO2_PIN , UltraSonic2_AF );

	cfg.DMA = DMA_2_;
	cfg.Chanel = CH_5_ ;
	cfg.Source_Address = (u32)(&TIM8_CCR2_REG);
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel2, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel2 , (void*)RET_NULLPTR);

	/**********  Channel   3   *********************************/

	DIO_setupPinMode( TRIGGER3_PORT , TRIGGER3_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER3_PORT ,  TRIGGER3_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO3_PORT , ECHO3_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO3_PORT ,ECHO3_PIN , UltraSonic3_AF );

	cfg.DMA = DMA_2_;
	cfg.Chanel = CH_1_ ;
	cfg.Source_Address = (u32)(&TIM8_CCR3_REG);
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel3, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel3 , (void*)RET_NULLPTR);

	/**********  Channel   4   *********************************/

	DIO_setupPinMode( TRIGGER4_PORT , TRIGGER4_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER4_PORT ,  TRIGGER4_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO4_PORT , ECHO4_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO4_PORT ,ECHO4_PIN , UltraSonic4_AF );

	cfg.DMA = DMA_1_;
	cfg.Chanel = CH_2_ ;
	cfg.Source_Address = (u32)(&TIM1_CCR1_REG);
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel4, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel4 , (void*)RET_NULLPTR);

	/**********  Channel   5   *********************************/

	DIO_setupPinMode( TRIGGER5_PORT , TRIGGER5_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER5_PORT ,  TRIGGER5_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO5_PORT , ECHO5_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO5_PORT ,ECHO5_PIN , UltraSonic5_AF );


	cfg.DMA = DMA_1_;
	cfg.Chanel = CH_3_ ;
	cfg.Source_Address = (u32)(&TIM1_CCR2_REG);
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel5, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel5 , (void*)RET_NULLPTR);

	/**********  Channel   6   *********************************/

	DIO_setupPinMode( TRIGGER6_PORT , TRIGGER6_PIN , PIN_OUTPUT );
	DIO_writePin( TRIGGER6_PORT ,  TRIGGER6_PIN , LOGIC_LOW );

	DIO_setupPinMode( ECHO6_PORT , ECHO6_PIN , PIN_ALTERNATE );
	DIO_setAlternateFunction(ECHO6_PORT ,ECHO6_PIN , UltraSonic6_AF );

	cfg.DMA = DMA_1_;
	cfg.Chanel = CH_6_ ;
	cfg.Source_Address = (u32)(&TIM1_CCR3_REG);
	DMA_Start(&cfg);

	ICU_SelectEdge(UltraSonic_Channel6, Both_Edges );
	ICU_INT_Enable(UltraSonic_Channel6 , (void*)RET_NULLPTR);


}

/*
 *  Description: Send the trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(DIO_PortID port , DIO_PinID pin , u8 Channel )
{
	UltraSonic_Channel = Channel;
	ICU_Control(UltraSonic_Channel , Enable);
	DIO_writePin( port ,  pin , LOGIC_HIGH );
	TIM6_Delay(10);
	DIO_writePin( port ,  pin , LOGIC_LOW );
}

/*
 * Description: Does the distance measurements and return with the distance
 */



u16 Ultrasonic_readDistance(void)
{
	static u16 distance = Read_Threshold ;
	u16 tim ;

	t1 = arr[0];
	t2 = arr[1];
	static u16 last_read;

	if( last_read != t2)
	{
		if( t1 > t2)
		{
			tim = ( 0xFFFF - t1 ) + t2 ;
		}
		else
		{
			tim = t2 - t1 ;
		}
		distance = ( tim / UltraSonic_HW_Calibartion ) ;
		last_read = t2;
	}
	else
	{
		distance = Read_Threshold;
	}

	if ( distance > Read_Threshold )
	{
		distance = Read_Threshold;
	}
	else
	{

	}

	ICU_Control(UltraSonic_Channel , Disable);

	return distance;
}




