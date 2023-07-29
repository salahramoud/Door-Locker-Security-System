/*
 * HMI_mcu.h
 *
 *  Created on: ٣٠‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#ifndef HMI_MCU_H_
#define HMI_MCU_H_
#include "std_types.h"



/*************************************************************************
 *                      Definitions
 ************************************************************************/

/* for check*/

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
#define STAND_PRESENTATION_TIME         1500
#define KEYPAD_CLICK_TIME         		500
#define OPEN_DOOR_TIME      			15
#define HOLD_DOOR_TIME       			3
#define CLOSE_DOOR_TIME      			15
#define WARNING_TIME           			60







/*****************************************************************************
 *                          Functions Prototype
 ****************************************************************************/

/*
 * to count tick of timer
 */
void HMI_TimerCallBackProcessing(void);



void HMI_startTimer(void);


/*
 * send command to mcu control
 */


void HMI_sendCommand(uint8 g_command);

/*
 * receive command from mcu control
 */
uint8 HMI_receiveCommand(void);

/*
 * to enter new password
 */
void HMI_newPassword(void);




/*
 * Description:
 * Function that takes Password characters form array
 * and Send that password to the CONTROL MCU through UART
 */
void HMI_sendPassword(uint8 a_inputPassword[]);



/*
 * function to get pass from keypad
 * then store it in array to use it later
 * and print * on the lcd
 */
void HMI_getPassword(uint8 a_inputPassword[]);




void HMI_mainOptions(void);

/*
 * ask user to enter password
 */
void HMI_promptPassword(void);



/*
 * timer
 */

void HMI_openingDoor(void);


void HMI_wrongPassword(void);









#endif /* HMI_MCU_H_ */
