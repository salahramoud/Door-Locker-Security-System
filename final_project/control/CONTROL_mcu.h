/*
 * CONTROL_mcu.h
 *
 *  Created on: ٠٢‏/١١‏/٢٠٢٢
 *      Author: salah ramoud
 */

#ifndef CONTROL_MCU_H_
#define CONTROL_MCU_H_

#include "std_types.h"

/*************************************************************************
 *                      Definitions
 ************************************************************************/

/* Definitions for Hand Shaking Protocol */
#define OPENING_DOOR          			0xF0
#define WRONG_PASSWORD        			0xF1
#define CHANGING_PASSWORD     			0xF2
#define OPEN_DOOR             			'+'
#define CHANGE_PASSWORD       			'-'
#define READY_TO_SEND         			0xF3
#define READY_TO_RECEIVE      			0xF4
#define RECEIVE_DONE          			0xF5
#define SEND_FIRST_PASSWORD   			0xF6
#define SEND_SECOND_PASSWORD 			0xF7
#define SEND_CHECK_PASSWORD   			0xF8

/* Definitions for Password */
#define PASSWORD_LENGTH         		5
#define MAX_NUM_OF_MISTAKES     		3
#define PASS_MIS_MATCHED              	0
#define PASS_MATCHED				  	1

/* Definitions for Time Periods */
#define SEND_RECEIVE_TIME      			10
#define OPEN_DOOR_TIME      			15
#define HOLD_DOOR_TIME       			3
#define CLOSE_DOOR_TIME      			15
#define WARNING_TIME           			60
#define STORING_TIME           			80

#define TWI_ADDRESS    0b0000001


/*****************************************************************************
 *                          Functions Prototype
 ****************************************************************************/


void CONTROL_TimerCallBackProcessing(void);
void CONTROL_startTimer(void);

/*
 * to get new password
 */
void CONTROL_newPassword(void);

/*
 * function to receive password
 */
void CONTROL_receivePassword(uint8 a_Password[]);

/*
 * function to compare password
 */
uint8 CONTROL_comparePasswords(uint8 a_password1[], uint8 a_password2[]);

/*
 * to save password to EEPROM
 */
void CONTROL_savePassword(uint8 a_receivedPassword[]);

/*
 * to read password
 */
void CONTROL_readPassword(uint8 a_storedPassword[]);
/*
 * to open door
 */
void CONTROL_openingDoor(void);


void CONTROL_wrongPassword(void);


/*
 * to send command
 */
void CONTROL_sendCommand(uint8 g_command);

/*
 * to receive command
 */
uint8 CONTROL_receiveCommand(void);


























#endif /* CONTROL_MCU_H_ */
