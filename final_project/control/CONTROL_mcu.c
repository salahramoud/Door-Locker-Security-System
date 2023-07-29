/*
 * CONTROL_mcu.c
 *
 *  Created on: ٠٢‏/١١‏/٢٠٢٢
 *      Author: salah ramoud
 */

/*****************************************************************************
 *                                Modulus
 ****************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "micro_config.h"

#include "CONTROL_mcu.h"
#include "uart.h"
#include "external_eeprom.h"
#include "DCmotor.h"
#include "buzzer.h"
#include "twi.h"
#include "timer.h"





/***************************************************************************
 *                              Global Variables
 ***************************************************************************/

uint8 g_command;
uint8 g_tick=0;
uint8 g_matchStatus=PASS_MIS_MATCHED;
uint8 g_storedPassword[PASSWORD_LENGTH];
uint8 g_receivedPassword[PASSWORD_LENGTH];
uint8 g_confirmPassword[PASSWORD_LENGTH];
uint8 g_passwordMistakes = 0;



/***************************************************************************
 *                              Functions Definitions
 **************************************************************************/

int main(void)
{
	uint8 key;
	SREG |=(1<<7);
	UART_ConfigType UART_config={9600,USART_8_BIT,ONE_BIT,DISABLED};
	UART_init(&UART_config);

	TWI_ConfigType twi_config={Prescalar_1,FastMode_400Kb,TWI_ADDRESS};
	TWI_init(&twi_config);

	DcMotor_Init();
	Buzzer_init();
	CONTROL_newPassword();

	while(1)
	{
		while(CONTROL_receiveCommand()!=SEND_CHECK_PASSWORD);
		CONTROL_receivePassword(g_receivedPassword);
		key=CONTROL_receiveCommand();

		switch(key)
		{
		case OPEN_DOOR:

			CONTROL_readPassword(g_storedPassword);
			g_matchStatus=CONTROL_comparePasswords(g_storedPassword,g_receivedPassword);
			if(g_matchStatus==PASS_MATCHED)
			{

		        CONTROL_sendCommand(OPENING_DOOR);

		        CONTROL_openingDoor();

			}
			else if(g_matchStatus==PASS_MIS_MATCHED)
			{
				CONTROL_sendCommand(WRONG_PASSWORD);

				CONTROL_wrongPassword();



			}
			break;

		case CHANGE_PASSWORD:

			CONTROL_readPassword(g_storedPassword);

			g_matchStatus = CONTROL_comparePasswords(g_receivedPassword, g_storedPassword);

			if(g_matchStatus == PASS_MATCHED)
			{
				CONTROL_sendCommand(CHANGING_PASSWORD);

				CONTROL_newPassword();


			}
			else if(g_matchStatus == PASS_MIS_MATCHED)
			{
				CONTROL_sendCommand(WRONG_PASSWORD);

				CONTROL_wrongPassword();

			}
			break;







		}


	}




}

void CONTROL_TimerCallBackProcessing(void)
{
	g_tick++;
}

void CONTROL_startTimer(void)
{
	TIMER_ConfigType Timer_config={TIMER1_ID,COMPARE,0,F_CPU_1024,7813};

	Timer_init(&Timer_config);
	Timer_setCallBack(CONTROL_TimerCallBackProcessing,TIMER1_ID);
}


void CONTROL_newPassword(void)
{
	g_matchStatus=PASS_MIS_MATCHED;

	while(g_matchStatus==PASS_MIS_MATCHED)
	{
		while(CONTROL_receiveCommand()!=SEND_FIRST_PASSWORD);

		CONTROL_receivePassword(g_receivedPassword);

		while(CONTROL_receiveCommand()!=SEND_SECOND_PASSWORD);


		CONTROL_receivePassword(g_confirmPassword);


		g_matchStatus=CONTROL_comparePasswords(g_receivedPassword,g_confirmPassword);

		if(g_matchStatus==PASS_MIS_MATCHED)
		{
			CONTROL_sendCommand(PASS_MIS_MATCHED);

		}
		else if(g_matchStatus==PASS_MATCHED)
		{
			CONTROL_savePassword(g_receivedPassword);
			CONTROL_sendCommand(PASS_MATCHED);

		}

	}
}

/*
 * Description :
 * Takes the Password which received from UART
 * and Store it in an array for later use
 */
void CONTROL_receivePassword(uint8 a_Password[])
{
	uint8 counter;

	for( counter = 0; counter < PASSWORD_LENGTH; counter++)
	{
		a_Password[counter]=UART_recieveByte();

		_delay_ms(SEND_RECEIVE_TIME);
	}
}

uint8 CONTROL_comparePasswords(uint8 a_password1[], uint8 a_password2[])
{
	uint8 counter;

	for(counter=0;counter<PASSWORD_LENGTH;counter++)
	{
		if(a_password1[counter]!= a_password2[counter])

		{
			return PASS_MIS_MATCHED;
		}
	}
	return PASS_MATCHED;


}


void CONTROL_savePassword(uint8 a_receivedPassword[])
{
	uint8 counter;
	for( counter = 0; counter < PASSWORD_LENGTH; counter++)
	{
		 EEPROM_writeByte((0x0311+counter),a_receivedPassword[counter]);
			_delay_ms(STORING_TIME);
	}


}
/*
 * Description :
 * Load the Password from EEPROM
 * and Store it in an array
 */
void CONTROL_readPassword(uint8 a_storedPassword[])
{
	uint8 counter;
	for( counter = 0; counter < PASSWORD_LENGTH; counter++)
	{
		EEPROM_readByte((0x0311+counter),&a_storedPassword[counter]);

		_delay_ms(STORING_TIME);

	}



}


void CONTROL_openingDoor(void)
{
	CONTROL_startTimer();
	while(g_tick!=OPEN_DOOR_TIME)
	{
		DcMotor_Rotate(CLOCKWISE);
	}
	g_tick=0;

	while(g_tick != HOLD_DOOR_TIME)
	{
		DcMotor_Rotate(STOP);
	}
	g_tick=0;
	while(g_tick!=CLOSE_DOOR_TIME)
	{
		DcMotor_Rotate(ANTI_CLOCKWISE);
	}

	DcMotor_Rotate(STOP);
    Timer_DeInit(TIMER1_ID); /* Stop the timer */
}



void CONTROL_wrongPassword(void)
{
	g_passwordMistakes++;
	if(g_passwordMistakes==MAX_NUM_OF_MISTAKES)
	{
		CONTROL_startTimer();
		while(g_tick !=WARNING_TIME)
		{
			Buzzer_on();

		}
		g_tick=0;
		g_passwordMistakes=0;


	    Timer_DeInit(TIMER1_ID); /* Stop the timer */



	}
	Buzzer_off();


}

void CONTROL_sendCommand(uint8 g_command)
{
	UART_sendByte(READY_TO_SEND);
	while(UART_recieveByte()!= READY_TO_RECEIVE);
	UART_sendByte(g_command);
	while(UART_recieveByte()!=RECEIVE_DONE);

}
uint8 CONTROL_receiveCommand(void)
{
	while(UART_recieveByte()!=READY_TO_SEND);
	UART_sendByte(READY_TO_RECEIVE);
	g_command=UART_recieveByte();
	UART_sendByte(RECEIVE_DONE);
	return g_command;


}




















