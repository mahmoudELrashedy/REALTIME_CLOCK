/*
 * get_pressed_key.c
 *
 * Created: 9/24/2023 8:57:40 AM
 *  Author: M
 */ 

#include "get_pressed_key.h"

unsigned char Key_configuration(unsigned char x) ; 

unsigned char Get_Pressed_key(void)
{
	DDRC|=0b11110000 ; 
	DDRC&=0xF0 ; 
	PORTC|=0x0F ; 
	while(1){
	for (unsigned char col = 0 ; col<4 ; col++){
		PORTC|=0xF0 ;
		PORTC&= ~(1<<(col+4)) ;
		
		for (unsigned char row = 0 ; row<4 ; row++){
			if (!(PINC&(1<<row))){
				_delay_ms(30) ; 
				
				if (!(PINC&(1<<row))){
					return Key_configuration((row*4)+col+1) ; 
				}
			}
		}
		
	}
}
}

unsigned char Key_configuration(unsigned char x)
{
	
	switch (x){
	
		case 1:
		return 7 ;
		break;
		
		case 2:
		return 8 ;
		break;
		
		case 3:
		return 9 ;
		break;
		
		case 4:
		return '/' ;
		break;
		
		case 5:
		return 4 ;
		break;
		
		case 6:
		return 5 ;
		break;
		
		case 7:
		return 6 ;
		break;
		
		case 8:
		return '*' ;
		break;
		
		case 9:
		return 1 ;
		break;
		
		case 10:
		return 2 ;
		break;
		
		case 11:
		return 3 ;
		break;
		
		case 12:
		return '-' ;
		break;
		
		case 13:
		return 'S' ;
		break;
		
		case 14:
		return 0 ;
		break;
		
		case 15:
		return '=' ;
		break;
		
		case 16:
		return '+' ;
		break;
		
		default:
		break;
	}
}