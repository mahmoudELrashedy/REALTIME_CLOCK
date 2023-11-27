/*
 * LCD_LIB.h
 *
 * Created: 9/16/2023 8:15:36 PM
 *  Author: M
 */ 


#ifndef LCD_LIB_H_
#define LCD_LIB_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define Data_Port_dir DDRA  
#define Data_Port PORTA
#define CTL_Port_dir DDRA
#define CTL_Port PORTA
#define RS 1
#define RW 2
#define EN 3

#define CLEAR_LCD  				    0x01
#define FOUR_BITS_DATA_MODE 		0x02
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define TWO_LINE_LCD_FOUR_BIT_MODE  0x28
#define CURSOR_OFF 					0x0C
#define CURSOR_ON 					0x0E
#define SET_CURSOR_LOCATION 		0x80

void LCD_Init (void);
void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_String(  char* string ) ;
void LCD_CLR (void) ;  



#endif /* LCD_LIB_H_ */