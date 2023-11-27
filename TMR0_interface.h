/*
 * TMR0_interface.h
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

#include "STD_TYPES.h"
#include "TMR0_private.h"
#include "TMR0_config.h"
            /*************** APIS PROTOTYPES ***************/
			
			
void TMR0_voidInit                (void);
void TMR0_voidStart               (void);
void TMR0_voidStop                (void);
void TMR0_voidSetCallBackOVF      (void(*ptrToFun)(void));
void TMR0_voidSetCallBackCTC      (void(*ptrToFun)(void));
void TMR0_voidSetCompareMatchValue(uint8 Copy_u8CompareValue);
void TMR0_voidetDelay_ms_usingCTC (uint16 Copy_u16Delay_ms);
void TMR0_voidSetDytyCycleFastPWM (uint8 Copy_u8DytyCycle);


#endif /* TMR0_INTERFACE_H_ */