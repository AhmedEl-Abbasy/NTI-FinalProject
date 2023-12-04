/*
 * pwm_reg.h
 *
 *  Created on: Nov 29, 2023
 *      Author: 2022
 */

#ifndef PWM_REG_H_
#define PWM_REG_H_

#include "std_types.h"



#define TIMER2_BASE_ADDR                (0x40000000ul )      // Base Address for TIMER8 in memory map


#define CR1_REG_OFFSET  		  (0x00u)	//16b
#define CCMR1_REG_OFFSET          (0x18u)   //32b
#define CCER_REG_OFFSET           (0x20u)   //32b
#define PSC_REG_OFFSET            (0x28u)   //16b
#define CCR1_REG_OFFSET           (0x34u)	//16b
#define CCR2_REG_OFFSET           (0x38u)	//16b
#define ARR_REG_OFFSET  		  (0x2Cu)	//16b
#define CNT_REG_OFFSET            (0x24u)   //16b



#define TIM2_CR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CR1_REG_OFFSET   ))
#define TIM2_PSC_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + PSC_REG_OFFSET   ))
#define TIM2_CCR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR1_REG_OFFSET  ))
#define TIM2_CCR2_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCR2_REG_OFFSET  ))
#define TIM2_CCER_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCER_REG_OFFSET  ))
#define TIM2_CCMR1_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CCMR1_REG_OFFSET ))
#define TIM2_CNT_REG					( *( volatile u32* ) ( TIMER2_BASE_ADDR + CNT_REG_OFFSET   ))
#define TIM2_ARR_REG                    ( *( volatile u32* ) ( TIMER2_BASE_ADDR + ARR_REG_OFFSET   ))



#define OC1M_BIT_4_5_6	    	(4u)
#define OC2M_BIT_12_13_14		(12u)

#define OC1PE_BIT_3			(3u)
#define OC2PE_BIT_11		(11u)




#define CC1E_BIT_0	 (0u)
#define CC2E_BIT_4	 (4u)



#define ARPE_BIT_7		(7u)
#define CEN_BIT_0		(0u)

#endif /* PWM_REG_H_ */
