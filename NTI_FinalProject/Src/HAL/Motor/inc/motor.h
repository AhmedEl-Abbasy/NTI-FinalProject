/*
 * DcMotor.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Abelrahman
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
#include "motor_types.h"


void DcMotor_Init(void);
void DcMotor_Rotate(Config_Motor * config_ptr );

#endif /* DCMOTOR_H_ */
