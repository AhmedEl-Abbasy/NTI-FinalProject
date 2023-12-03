/*
 * pwm.c
 *
 *  Created on: Nov 29, 2023
 *      Author: 2022
 */

#include "pwm.h"


void PWM_Init(void)
{

	TIM2_PSC_REG = ( 800 - 1 ) ;			// tick = 100 micro sec
	TIM2_ARR_REG = ( 100 - 1 ) ;			// reload evrey 10 mili sec  ==> freq = 10 mili sec
	TIM2_CNT_REG = 0;
	TIM2_CCMR1_REG |= WriteValue(6,OC1M_BIT_4_5_6);		//011
	TIM2_CCMR1_REG |= WriteValue(6,OC2M_BIT_12_13_14);	//011

	SET_BIT(TIM2_CCMR1_REG,OC1PE_BIT_3);
	SET_BIT(TIM2_CCMR1_REG,OC2PE_BIT_11);

    SET_BIT(TIM2_CR1_REG,ARPE_BIT_7);

}

void PWM_Start(PWM_Channel  channel , u8 Duty)
{
	switch(channel )
	{
    CLEAR_BIT(TIM2_CR1_REG,CEN_BIT_0);			// disable the timer
	case channel1:

		CLEAR_BIT(TIM2_CCER_REG , CC1E_BIT_0 );		// disable the channel
		if(Duty == 0)
			Duty = 1;
		TIM2_CCR1_REG = ( ( Duty * 1 ) - 1 );
		SET_BIT(TIM2_CCER_REG , CC1E_BIT_0);		//enable the channel

	break;
	case channel2:

		CLEAR_BIT(TIM2_CCER_REG , CC2E_BIT_4 );
		TIM2_CCR2_REG = ( ( Duty * 1 ) - 1 );
		SET_BIT(TIM2_CCER_REG , CC2E_BIT_4);

	break;
	}
    SET_BIT(TIM2_CR1_REG,CEN_BIT_0);		//enable the timer

}
