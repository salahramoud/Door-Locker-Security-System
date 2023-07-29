/*
 * buzzer.h
 *
 *  Created on: ٢٦‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"



/***************************************************************************
 *                           Definitions
 **************************************************************************/

#define BUZZER_PORT_ID       PORTA_ID
#define BUZZER_PIN_ID        PIN0_ID


/****************************************************************************
 *                      Function Prototype
 ***************************************************************************/

/*
 * Description
 * Functional responsible for Initialize the Buzzer device
 */
void Buzzer_init();


/*
 * Description
 * Function to enable the Buzzer through the GPIO.
 */

void Buzzer_on(void);




/*
 * Description
 * Function to disable the Buzzer through the GPIO
 */

void Buzzer_off(void);

#endif /* BUZZER_H_ */
