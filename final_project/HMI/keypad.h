/*
 * keypad.h
 *
 *  Created on: Oct 12, 2022
 *      Author: salah ramoud
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"

/* Keypad configurations for number of rows and columns */
//#define STANDARD_KEYPAD   //if i want to use standard keypad make this line un commented
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */

#define KEYPAD_ROW_PORT_ID                PORTC_ID
#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID

#define KEYPAD_COL_PORT_ID                PORTC_ID
#define KEYPAD_FIRST_COL_PIN_ID           PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH
    // functions prototypes
uint8 KEYPAD_getPressedKey(void);


#endif /* KEYPAD_H_ */
