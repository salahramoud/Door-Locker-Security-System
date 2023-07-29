 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author:  salah ramoud
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "micro_config.h"



/*************************************************************************
 *                        Types Declaration
 **************************************************************************/

typedef enum
{
	USART_5_BIT,USART_6_BIT,USART_7_BIT,USART_8_BIT,USART_9_BIT=7


}UART_BitData;

typedef enum
{
	DISABLED,RESERVED,EVEN,ODD

}UART_Parity;

typedef enum
{
	ONE_BIT,TWO_BIT

}UART_StopBit;







typedef struct
{
	uint32 baud_rate;
	UART_BitData bit_data;
	UART_StopBit stop_bit;
	UART_Parity parity;


}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType *Config_Ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
