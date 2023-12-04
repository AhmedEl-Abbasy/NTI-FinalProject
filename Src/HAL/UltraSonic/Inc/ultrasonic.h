
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "bit_math.h"
#include "rcc.h"
#include "dio.h"
#include "icu.h"
#include "NVIC.h"
#include "TIM6.h"
//#include "sysTick.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*HW Interfacing Ports and Pins*/

/***************  Tim8        *****************/
/*    ICU alternative mode       */

// Channel 1 =============>>>>>          PC6 => AF4 , PA15 => AF2 , PB6 => AF5
// Channel 2 =============>>>>>          PC7 => AF4 , PA14 => AF5 , PB8 => AF10
// Channel 3 =============>>>>>          PC8 => AF4 , PB9 => AF10


/***************  Tim1        *****************/

// Channel 4 =============>>>>>          PA8=>AF6  ,  PC0=>AF2
// Channel 5 =============>>>>>          PA9=>AF6  ,  PC1=>AF2
// Channel 6 =============>>>>>          PA10=>AF6 ,  PC2=>AF2




/*************************    Channel   1    *************************************/


#define TRIGGER1_PORT        	  PORTA_ID
#define TRIGGER1_PIN       		  PIN0_ID

#define ECHO1_PORT         		  PORTC_ID
#define ECHO1_PIN          		  PIN6_ID

#define UltraSonic_Channel1  	  channel_1
#define UltraSonic1_AF  		  AF4


/*************************************************************************************/


/*************************    Channel   2    *************************************/


#define TRIGGER2_PORT      		  PORTA_ID
#define TRIGGER2_PIN       		  PIN1_ID

#define ECHO2_PORT         		  PORTC_ID
#define ECHO2_PIN          		  PIN7_ID

#define UltraSonic_Channel2  	  channel_2
#define UltraSonic2_AF  		  AF4


/*************************************************************************************/


/*************************    Channel   3    *************************************/


#define TRIGGER3_PORT       	  PORTA_ID
#define TRIGGER3_PIN       		  PIN4_ID

#define ECHO3_PORT         		  PORTC_ID
#define ECHO3_PIN          		  PIN8_ID

#define UltraSonic_Channel3  	  channel_3
#define UltraSonic3_AF  		  AF4


/*************************    Channel   4    *************************************/


#define TRIGGER4_PORT             PORTB_ID
#define TRIGGER4_PIN              PIN0_ID

#define ECHO4_PORT                PORTC_ID
#define ECHO4_PIN                 PIN0_ID

#define UltraSonic_Channel4  	  channel_4
#define UltraSonic4_AF  		  AF2

/*************************************************************************************/


/*************************    Channel   5    *************************************/


#define TRIGGER5_PORT            PORTF_ID
#define TRIGGER5_PIN             PIN1_ID

#define ECHO5_PORT               PORTC_ID
#define ECHO5_PIN                PIN1_ID

#define UltraSonic_Channel5  	channel_5
#define UltraSonic5_AF  		AF2


/*************************************************************************************/


/*************************    Channel   6    *************************************/


#define TRIGGER6_PORT           PORTF_ID
#define TRIGGER6_PIN            PIN1_ID

#define ECHO6_PORT              PORTC_ID
#define ECHO6_PIN               PIN2_ID

#define UltraSonic_Channel6  	channel_6
#define UltraSonic6_AF  		AF2


/*************************************************************************************/


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/***************  Channels  ***********************/







/*Call Back function*/
void Ultrasonic_edgeProcessing(void);
/*initialization Function of the Ultrasonic driver*/
void Ultrasonic_init(void);


void Ultrasonic_Trigger(DIO_PortID port , DIO_PinID pin , u8 Channel );

/*Does the distance measurements and return with the distance*/
u16 Ultrasonic_readDistance(void);




#endif /* ULTRASONIC_H_ */
