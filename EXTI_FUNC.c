/*
 * EXTI_FUNC.c
 *
 * Created: 9/27/2023 10:15:32 AM
 *  Author: M
 */ 
#include "EXTI_REG.h"
#include "EXTI_FUNC.h"
#include "BIT_MATH.h"

static void (*EXTI_pCallBackINT0)(void) = 0 ; 
static void (*EXTI_pCallBackINT1)(void) = 0 ; 
static void (*EXTI_pCallBackINT2)(void) = 0 ;

void EXTI_VoidEnable(EXTI_source_t Copy_IntrruptSource , EXTI_trigger_t Copy_IntrruptTrigger) 
{
	switch(Copy_IntrruptSource){
		case EXTI_INT0:
		switch(Copy_IntrruptTrigger){
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ; 
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ;
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
			break;
			
			default:
			break;
		}
		SET_BIT(GICR,INT0);
		break;
		
		case EXTI_INT1:
		switch(Copy_IntrruptTrigger){
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ;
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00) ;
			SET_BIT(MCUCR,ISC01) ;
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
			break;
			
			case (EXTI_LOW_LEVEL):
			CLR_BIT(MCUCR,ISC00) ;
			CLR_BIT(MCUCR,ISC01) ;
			break;
			
			default:
			break;
		}
		SET_BIT(GICR,INT1);
		break;
		
		case EXTI_INT2:
		switch(Copy_IntrruptTrigger){
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,ISC2) ;
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2) ;
			break;
			
			default:
			break;
		}
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXTI_VoidDisable(EXTI_source_t Copy_IntrruptSource )
{
	switch(Copy_IntrruptSource){
		case EXTI_INT0:
		CLR_BIT(GICR,INT0) ;
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,INT1) ;
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,INT2) ;
		break;
	}
}

void EXTI_VoidSetCallBackINT0(void (*ptrToFun)(void))
{
	if (ptrToFun!=0)
	EXTI_pCallBackINT0 = ptrToFun ; 
}

void EXTI_VoidSetCallBackINT1(void (*ptrToFun)(void))
{
	if (ptrToFun!=0)
	EXTI_pCallBackINT1 = ptrToFun ;
}

void EXTI_VoidSetCallBackINT2(void (*ptrToFun)(void))
{
	if (ptrToFun!=0)
	EXTI_pCallBackINT2 = ptrToFun ;
}

void __vector_1(void)__attribute__((signal)) ;

void __vector_1(void)
{
	if (EXTI_pCallBackINT0!=0)
	EXTI_pCallBackINT0() ; 
} 

void __vector_2(void)__attribute__((signal)) ;

void __vector_2(void)
{
	if (EXTI_pCallBackINT1!=0)
	EXTI_pCallBackINT1() ;
}

void __vector_3(void)__attribute__((signal)) ;

void __vector_3(void)
{
	if (EXTI_pCallBackINT2!=0)
	EXTI_pCallBackINT2() ;
}