/*
 * pwm.h
 *
 *  Created on: Nov 29, 2023
 *      Author: 2022
 */

#ifndef PWM_H_
#define PWM_H_


#include "bit_math.h"
#include "std_types.h"
#include "pwm_reg.h"

typedef enum
{
    channel1,
    channel2
}PWM_Channel;

void PWM_Init(void);
void PWM_Start(PWM_Channel  channel , u8 Duty);




#endif /* PWM_H_ */
