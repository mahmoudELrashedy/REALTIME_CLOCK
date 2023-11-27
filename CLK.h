/*
 * CLK.h
 *
 * Created: 11/23/2023 11:20:42 AM
 *  Author: M
 */ 


#ifndef CLK_H_
#define CLK_H_

/*
	function name        : Set_Clock
	arguments            : void 
	return               : void
	function description : read user input clock 
*/
void Set_Clock (void)  ;

/*
	function name        : Start_Clock
	arguments            : void 
	return               : void
	function description : using TMR0 interrupt on compare match this function increases the counters of minutes and hours
*/
void Start_Clock(void) ;

/*
	function name        : Write_Clock
	arguments            : void 
	return               : void
	function description :display the input digit on the 7 segment while reading user input clock 
*/
void Clock_Write(void) ;

/*
	function name        : Set_Alarm
	arguments            : void 
	return               : void
	function description : read user input alarm time  
*/
void Set_Alarm (void) ; 

/*
	function name        : Alarm_Ringtone
	arguments            : void 
	return               : void
	function description : put a logical 1 on the buzzer pin when the alarm time matches the clock time
						   then clear the buzzer pin when the "stop ringtone" button is pressed
*/
void Alarm_Ringtone (void) ; 

/*
	function name        : Mode_Manage
	arguments            : void 
	return               : void
	function description : define each mode characteristics using predefined functions
*/
void Mode_Manage (void) ; 

/*
	function name        : Mode_Select
	arguments            : void 
	return               : void
	function description : change the current mode when external interrupt flag is raised
*/
void Mode_Select (void) ; 

typedef enum MODE {SET_CLK , ALARM , STOP_WATCH , RUN_CLK} MODE;
	


#endif /* CLK_H_ */