/*
 * timer.h
 *
 *  Created on: ٢٥‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "std_types.h"

/***********************************************************************************
 *
 *                        Typed Declarations
 *
 ***********************************************************************************/

typedef enum{
	TIMER0_ID,TIMER1_ID,TIMER2_ID

}TIMER_ID;

typedef enum{
	OVERFLOW,COMPARE

}TIMER_MODE;

typedef enum{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_FALLING_CLOCK,EXTERNA_RAISING_CLOCK


}TIMER_CLOCK;


typedef struct{
	TIMER_ID timer_id;
	TIMER_MODE timer_mode;
	uint16 intial_value;
	TIMER_CLOCK timer_clock;
	uint16 compare_value;




}TIMER_ConfigType;

/****************************************************************************************
 *
 *                      Function Prototypes
 *
 ****************************************************************************************/
/*
 * Description :
 * Function to Initialize the Timer by following predefined configurations
 * 		1. Choose which Timer to work with 							--> Timer0 / Timer1 / Timer2
 * 		2. Choose which mode to operate in 							--> Overflow Mode / Compare Mode
 * 		3. Choose which initial value to start the counting from
 * 		4. Choose the prescaler of the CPU clock to generate a clock for Timer to operate by
 * 		5. Choose Compare Value if the Timer operate in Compare Mode
 */


void Timer_init(const TIMER_ConfigType * Config_Ptr);



/*
 * Description
 *
 * function to disable timer
 *
 *
 */


void Timer_DeInit(TIMER_ID timer_number);

/*
 * Description :
 * Function to set the Call Back Function Address
 */

void Timer_setCallBack(void(*a_ptr)(void),TIMER_ID timer_number);










#endif /* TIMER_H_ */
