/*
 * TMR0_private.h
 *
 */ 


#ifndef TMR0_PRIVATE_H_
#define TMR0_PRIVATE_H_

/* MACROS FOR TIMER0 MODE CONFIGURATIONS */
#define TMR0_NORMAL_MODE            1
#define TMR0_CTC_MODE               2
#define TMR0_FAST_PWM_MODE          3

/* MACROS FOR TIMER0 PWM CONFIGURATIONS */
#define TMR0_PWM_NON_INVERTING      1
#define TMR0_PWM_INVERTING          2


                          /* TIMER0 REGISTERS*/
								 
// Timer/Counter Control Register
#define TCCR0            (*(volatile uint8*)0x53)
#define CS00             0
#define CS01             1
#define CS02             2
#define WGM01            3
#define COM00            4
#define COM01            5
#define WGM00            6
#define FOC0             7

// Timer/Counter Register
#define TCNT0            (*(volatile uint8*)0x52)

// Output Compare Register
#define OCR0             (*(volatile uint8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK            (*(volatile uint8*)0x59)
#define TOIE0            0
#define OCIE0            1

// Timer/Counter Interrupt Flag Register
#define TIFR             (*(volatile uint8*)0x58)
#define TOV0             0
#define OCF0             1



#endif /* TMR0_PRIVATE_H_ */