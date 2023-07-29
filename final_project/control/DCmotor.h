/*
 * DCmotor.h
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٢
 *      Author:  salah ramoud
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_


#include "std_types.h"
/**************************************************************************
 *
 *                        Definition
 *
 **************************************************************************/
#define DC_MOTOR_PORT1_ID   PORTB_ID
#define DC_MOTOR_PORT2_ID   PORTB_ID

#define DC_MOTOR_PIN1_ID    PIN0_ID
#define DC_MOTOR_PIN2_ID    PIN1_ID


/**************************************************************************
 *
 *                      Types Declaration
 *
 **************************************************************************/
typedef enum {
	STOP,CLOCKWISE,ANTI_CLOCKWISE

}DcMotor_State;
void DcMotor_Init(void);


void DcMotor_Rotate(DcMotor_State state);





#endif /* DCMOTOR_H_ */
