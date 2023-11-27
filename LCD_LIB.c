/*
 * LCD_LIB.c
 *
 * Created: 9/16/2023 8:15:59 PM
 *  Author: M
 */ 

#include "LCD_LIB.h"
void LCD_Init()
{
	Data_Port_dir |= 0xf0 ; 
	CTL_Port_dir |= (1<<RS) | (1<<RW)| (1<<EN) ; 
	
	_delay_ms(20) ; 
	
	LCD_Command(FOUR_BITS_DATA_MODE) ; 
	LCD_Command(TWO_LINE_LCD_FOUR_BIT_MODE) ; 
	LCD_Command(CLEAR_LCD) ; 
	LCD_Command(CURSOR_OFF) ; 
}

void LCD_Command( unsigned char cmnd )
{
	Data_Port = (Data_Port & 0x0f) | (cmnd & 0xf0) ; 
	CTL_Port &= ~(1<<RS) ; 
	CTL_Port &= ~(1<<RW) ; 
	
	CTL_Port |= (1<<EN) ; 
	_delay_us(1) ; 
	CTL_Port &= ~(1<<EN) ;
	_delay_us(200) ; 
	
	Data_Port = (Data_Port & 0x0f) | (cmnd <<4) ; 
	
	CTL_Port |= (1<<EN) ;
	_delay_us(1) ;
	CTL_Port &= ~(1<<EN) ;
	_delay_ms(2) ;
	
	
}

void LCD_Char( unsigned char data )
{
	Data_Port = (Data_Port & 0x0F) | (data & 0xF0) ;
	CTL_Port |= (1<<RS) ;
	CTL_Port &= ~(1<<RW) ;
	
	CTL_Port |= (1<<EN) ;
	_delay_us(1) ;
	CTL_Port &= ~(1<<EN) ;
	_delay_us(200) ;
	
	Data_Port = (Data_Port & 0x0F) | (data <<4) ;
	
	CTL_Port |= (1<<EN) ;
	_delay_us(1) ;
	CTL_Port &= ~(1<<EN) ;
	_delay_ms(2) ;
}

void LCD_String( char* string )
{
	for (int i = 0 ; string[i] !=0 ; i++){
		LCD_Char( string[i]) ; 
		
	}
	
	_delay_ms(2) ;
}