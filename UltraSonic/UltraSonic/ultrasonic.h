
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "bit_math.h"
#include "rcc.h"
#include "dio.h"
#include "icu.h"
#include "NVIC.h"
#include "sysTick.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*HW Interfacing Ports and Pins*/

/*    dio output mode       */
#define TRIGGER_PORT      PORTA_ID
#define TRIGGER_PIN       PIN1_ID

/*    ICU alternative mode       */
#define ECHO_PORT         PORTC_ID				// PC6 => AF4 , PA15 => AF2 , PB6 => AF5
#define ECHO_PIN          PIN6_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*Call Back function*/
void Ultrasonic_edgeProcessing(void);

/*initialization Function of the Ultrasonic driver*/
void Ultrasonic_init(void);


void Ultrasonic_Trigger(void);

/*Does the distance measurements and return with the distance*/
u16 Ultrasonic_readDistance(void);




#endif /* ULTRASONIC_H_ */
