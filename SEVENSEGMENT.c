/*
 * SEVENSEGMENT.c
 *
 * Created: 10/25/2023 7:04:04 AM
 *  Author: M
 */ 

//#include "get_pressed_key.h"
#include <avr/io.h>
#include "BIT_MATH.h"
#include "SEVENSEGMENT.h"



char pattern[10] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F } ; 

void Seg_Write (unsigned char pin , unsigned char val)
{
	//DDRB |= 0xFF ;
	//PORTB|= 0xF0 ;
	
	CLR_BIT(PORTB,pin) ;
	PORTB = ((PORTB & 0xF0) | val ) ;
	//_delay_ms(2000) ;
	//PORTB = ((PORTB & 0xF0) | ((pattern[val])>>4) ) ;
	_delay_ms(200) ;
	SET_BIT(PORTB,pin) ;
}	

void Seg_Display (unsigned char pin , unsigned char val)
{
	//DDRB |= 0xFF ;
	//PORTB|= 0xF0 ;
	
	CLR_BIT(PORTB,pin) ;
	PORTB = ((PORTB & 0xF0) | val ) ;
	//_delay_ms(5) ;	
	//PORTB = ((PORTB & 0xF0) | ((pattern[val])>>4) ) ;	                                             //pattern[val]
	_delay_ms(5) ;
	SET_BIT(PORTB,pin) ;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*static unsigned char i = 0 , j = 0 , k = 0 , l = 0 ; 

void Set_Clock (void)
{
	DDRB|=0x0F ;
	PORTB|=0x0F ; 
	DDRA|=0xFF ;
	
	 
	i = Get_Pressed_key() ;
	CLR_BIT(PORTB,0) ;
	PORTA = pattern[i] ; 
	_delay_ms(200) ; 
	SET_BIT(PORTB,0) ; 
	
	j = Get_Pressed_key() ;
	CLR_BIT(PORTB,1) ;
	PORTA = pattern[j] ;
	_delay_ms(200) ;
	SET_BIT(PORTB,1) ;
	
	k = Get_Pressed_key() ;
	CLR_BIT(PORTB,2) ;
	PORTA = pattern[k] ;
	_delay_ms(200) ;
	SET_BIT(PORTB,2) ;
	
	l = Get_Pressed_key() ;
	CLR_BIT(PORTB,3) ;
	PORTA = pattern[l] ;
	_delay_ms(200) ;
	SET_BIT(PORTB,3) ;
	
	
}

void Start_Clock(void)
{
	DDRB|=0x0F ;
	PORTB|=0x0F ;
	DDRA|=0xFF ;
	
		
		if (l < 9)
		{
			l++ ;
		}
		
		else if (k < 5)
		{
			l = 0 ;
			k++ ;
		}
		
		else if ((j < 9 && i < 2) || (j < 3 && i == 2)     )
		{
			l = 0 ;
			k = 0 ;
			j++ ;
		}
		
		else if (i < 2)
		{
			l = 0 ;
			k = 0 ;
			j = 0 ;
			i++ ;
		}
		
		else
		{
			l = 0 ;
			k = 0 ;
			j = 0 ;
			i = 0 ;
		}
		
		
	
}

void Clock_Write(void)
{
	CLR_BIT(PORTB,0) ;
	PORTA = pattern[i] ;
	_delay_ms(10) ;
	SET_BIT(PORTB,0) ;
	
	CLR_BIT(PORTB,1) ;
	PORTA = pattern[j] ;
	_delay_ms(10) ;
	SET_BIT(PORTB,1) ;
	
	CLR_BIT(PORTB,2) ;
	PORTA = pattern[k] ;
	_delay_ms(10) ;
	SET_BIT(PORTB,2) ;
	
	CLR_BIT(PORTB,3) ;
	PORTA = pattern[l] ;
	_delay_ms(10) ;
	SET_BIT(PORTB,3) ;
}*/