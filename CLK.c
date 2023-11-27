/*
 * CLK.c
 *
 * Created: 11/23/2023 11:20:26 AM
 *  Author: M
 */ 

#include "get_pressed_key.h"
#include <avr/io.h>
#include "BIT_MATH.h"
#include "SEVENSEGMENT.h"
#include "CLK.h"
#include "LCD_LIB.h"

#include "GI_FUNC.h"
#include "EXTI_FUNC.h"

#include <stdlib.h>

static unsigned char i = 0 , j = 0 , k = 0 , l = 0 ;
static unsigned char alarm_i = 0 , alarm_j = 0 , alarm_k = 0 , alarm_l = 0 ;
static unsigned char stop_i = 0 , stop_j = 0 , stop_k = 0 , stop_l = 0 ; 

static MODE mode = 0 ; 

void Set_Clock (void)
{
	DDRB |= 0xFF ;
	PORTB|= 0xF0 ;
	LCD_Command(SET_CURSOR_LOCATION) ; 
	LCD_String(" Set your clock ") ; 
	i = Get_Pressed_key() ;
	Seg_Write (4 , i) ; 
	_delay_ms(100) ; 
	j = Get_Pressed_key() ;
	Seg_Write (5 , j) ;
	_delay_ms(100) ; 
	k = Get_Pressed_key() ;
	Seg_Write (6 , k) ;
	_delay_ms(100) ; 
	l = Get_Pressed_key() ;
	Seg_Write (7 , l) ;
	_delay_ms(100) ; 
	LCD_Command(CLEAR_LCD) ;
	
}

void Set_StopWatch (void)
{
	DDRB |= 0xFF ;
	PORTB|= 0xF0 ;
	
	LCD_Command(SET_CURSOR_LOCATION) ; 
	LCD_String(" Set StopWatch ") ;
	stop_i = Get_Pressed_key() ;
	Seg_Write (4 , stop_i) ;
	_delay_ms(100) ;
	stop_j = Get_Pressed_key() ;
	Seg_Write (5 , stop_j) ;
	_delay_ms(100) ;
	stop_k = Get_Pressed_key() ;
	Seg_Write (6 , stop_k) ;
	_delay_ms(100) ;
	stop_l = Get_Pressed_key() ;
	Seg_Write (7 , stop_l) ;
	_delay_ms(100) ;
	LCD_Command(CLEAR_LCD) ;
	
}

void Start_Clock(void)
{
	
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
	
	if (stop_l>0)
	stop_l -- ; 
	else if (stop_k>0)
	stop_k -- ; 
	else if (stop_j>0)
	stop_j -- ;
	else if (stop_j>0)
	stop_j -- ;
	
	
}

void Clock_Write(void)
{
	 LCD_Command(SET_CURSOR_LOCATION+3) ; 
	LCD_String("Clock mode") ; 
	Seg_Display (4 , i) ; 
	
	Seg_Display (5 , j) ; 
	
	Seg_Display (6 , k) ; 
	
	Seg_Display (7 , l) ; 
	
}


void StopWatch_Write(void)
{
	LCD_Command(SET_CURSOR_LOCATION) ;
	LCD_String("StopWatch mode") ;
	Seg_Display (4 , stop_i) ;
	
	Seg_Display (5 , stop_j) ;
	
	Seg_Display (6 , stop_k) ;
	
	Seg_Display (7 , stop_l) ;
	
}



void Set_Alarm (void)
{
	DDRB |= 0xFF ;
	PORTB|= 0xF0 ;
	
	LCD_Command(SET_CURSOR_LOCATION+1) ;
	LCD_String(" Set your alarm ") ;
	alarm_i = Get_Pressed_key() ;
	Seg_Write (4 , alarm_i) ;
	_delay_ms(100) ; 
	
	alarm_j = Get_Pressed_key() ;
	Seg_Write (5 , alarm_j) ;
	_delay_ms(100) ; 
	
	alarm_k = Get_Pressed_key() ;
	Seg_Write (6 , alarm_k) ;
	_delay_ms(100) ; 
	
	alarm_l = Get_Pressed_key() ;
	Seg_Write (7 , alarm_l) ;
	_delay_ms(100) ; 
	
	int x = (alarm_j) + (alarm_i*10) ; 
	int y = (alarm_l) + (alarm_k*10) ;
	char buff[20] ; 
	itoa(x,buff,10) ; 
	LCD_Command(CLEAR_LCD) ;
	
	LCD_Command(SET_CURSOR_LOCATION+(0x40)) ;
	LCD_String("alarm at : ") ;
	LCD_String(buff) ;
	  
	LCD_Char(':') ; 
	itoa(y,buff,10) ; 
	LCD_String(buff) ; 
	
	
}

void Alarm_Ringtone ()
{
	SET_BIT(DDRD,7) ; 
	CLR_BIT(DDRD,2) ;
	SET_BIT(PORTD,2) ; 
	if (alarm_i == i &&  alarm_j == j &&  alarm_k == k &&  alarm_l == l){
	while (READ_BIT(PIND,2)){
	SET_BIT(PORTD,7) ;
	Clock_Write() ; 
	}
	CLR_BIT(PORTD,7);
	alarm_i = 0 ; alarm_j = 0 ; alarm_k = 0 ; alarm_l = 0 ; 
	}
	
}

void Mode_Manage ()
{
	
	CLR_BIT(DDRD,3);
	SET_BIT(PORTD,3);
	
	EXTI_VoidEnable(EXTI_INT1 , EXTI_RISING_EDGE) ;
	EXTI_VoidSetCallBackINT1(Mode_Select) ;
	GI_VoidEnable() ; 
	
	
	//mode++ ; 
	if (mode == SET_CLK)
	{
		 
		Set_Clock () ;
		while(mode == SET_CLK)
		{
			Clock_Write() ; 
			
		} 
		
	}
	
	if (mode == ALARM)
	{
		
		Set_Alarm () ;
		
		while(mode == ALARM)
		{
			Clock_Write() ;
			Alarm_Ringtone () ; 
		} 
		
	}
	
	if (mode == STOP_WATCH)
	{
		SET_BIT(DDRD,7) ;
		CLR_BIT(DDRD,2) ;
		SET_BIT(PORTD,2) ;
		
		Set_StopWatch () ;
		while(mode == STOP_WATCH)
		{
			StopWatch_Write() ;
			if (stop_l == 0 )
			{
				while(READ_BIT(PIND,2))
				{
					SET_BIT(PORTD,7) ;
					StopWatch_Write() ;
					//if ((READ_BIT(PIND,2)) == 0)
					//break;
				}
				
				CLR_BIT(PORTD,7) ;
				LCD_Command(CLEAR_LCD) ; 
				mode = RUN_CLK ; 
				
			}
		} 
	}
	
	if (mode == RUN_CLK)
	{
		
		
		while(mode == RUN_CLK)
		{
			Clock_Write() ;
			
		}
	}

}


void Mode_Select (void) 
{
	if (mode<3)
	mode++ ; 
	else
	mode = 1 ; 
}
