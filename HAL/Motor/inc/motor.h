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
#include <motor_cnfg.h>


//void DcMotor_Init(void);
void DcMotor_Init(Motor_ID_t* motor );
void DcMotor_Rotate(Motor_ID_t* motor );

#endif /* DCMOTOR_H_ */
