/*
 * motor_types.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Abelrahman
 */

#ifndef MOTOR_INC_MOTOR_TYPES_H_
#define MOTOR_INC_MOTOR_TYPES_H_

typedef enum DcMotorState {
	off,
	on
}DcMotor_State;

typedef enum DcMotorDirection {
	clockwise=1,
	anticlockwise
}DcMotor_direction;

typedef struct MotorConfig {
	DcMotor_State state ;
	DcMotor_direction direction;
	u8 speed;
}Config_Motor;

typedef struct Motor_ID {
	u8 MotorPortID ;
	u8 MootorPin1;
	u8 MootorPin2;
	u8 MotorPortID_PWM;
	u8 MootorPin_PWM;
	Config_Motor motor_id;
}Motor_ID_t;




#endif /* MOTOR_INC_MOTOR_TYPES_H_ */
