/*
 * REALTIME_CLOCK.c
 *
 * Created: 10/25/2023 6:37:50 AM
 * Author : M
 */ 


#include "SEVENSEGMENT.h"
#include "GI_FUNC.h"
#include "EXTI_FUNC.h"
#include "TMR0_interface.h"
#include "CLK.h"
#include "LCD_LIB.h"
#include "BIT_MATH.h"
int main(void)
{
	//CLR_BIT(DDRD,3);
	//SET_BIT(PORTD,3);
	LCD_Init() ; 
	
   
	
	GI_VoidEnable() ; 
	
	TMR0_voidInit                ();
	TMR0_voidStart               ();
	
	TMR0_voidetDelay_ms_usingCTC (30000);
	TMR0_voidSetCallBackCTC      (Start_Clock);
	
	 //EXTI_VoidEnable(EXTI_INT1 , EXTI_RISING_EDGE) ; 
	 //EXTI_VoidSetCallBackINT1(Mode_Select) ;
	 
	 
    while (1) 
    {
		Mode_Manage() ; 
    }
}

