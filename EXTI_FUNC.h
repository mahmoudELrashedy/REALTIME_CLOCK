/*
 * EXTI_FUNC.h
 *
 * Created: 9/27/2023 10:15:09 AM
 *  Author: M
 */ 


#ifndef EXTI_FUNC_H_
#define EXTI_FUNC_H_

typedef enum{
	EXTI_INT0=0,
	EXTI_INT1=1,
	EXTI_INT2=2
	
	}EXTI_source_t;

typedef enum{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
	}EXTI_trigger_t;
	
	
	
void EXTI_VoidEnable(EXTI_source_t , EXTI_trigger_t) ; 
void EXTI_VoidDisable(EXTI_source_t ) ;

void EXTI_VoidSetCallBackINT0(void (*ptrToFun)(void)) ; 
void EXTI_VoidSetCallBackINT1(void (*ptrToFun)(void)) ;
void EXTI_VoidSetCallBackINT2(void (*ptrToFun)(void)) ;



#endif /* EXTI_FUNC_H_ */