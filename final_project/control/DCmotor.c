/*
 * DCmotor.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٢
 *      Author:  salah ramoud
 */


#include "DCmotor.h"
#include "gpio.h"
#include "common_macros.h"


void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT); //PB0 output pin for motor
	GPIO_setupPinDirection(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);//PB1 output pin for motor

	//GPIO_writePin(PORTB_ID,PIN3_ID,LOGIC_HIGH);

	GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);  //stop motor at beginning
	GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);

}


void DcMotor_Rotate(DcMotor_State state)
{
	switch(state)
	{
	case 0:
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_HIGH);
		break;

	}


}


