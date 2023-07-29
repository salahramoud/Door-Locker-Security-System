/*
 * buzzer.c
 *
 *  Created on: ٢٦‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#include "buzzer.h"
#include "gpio.h"


/**************************************************************************
 *                      Functions Definition
 **************************************************************************/

void Buzzer_init()
{
	//make buzzer output
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);

	//set buzzer off
	 GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);



}
void Buzzer_on(void)
{
	/* make pin high*/
	 GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);


}
void Buzzer_off(void)
{
	/*make pin low */
	 GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);


}





