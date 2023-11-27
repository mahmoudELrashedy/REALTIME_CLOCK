/*
 * TMR0_program.c
 *
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"


static void (*private_pCallBackOVF)(void) = 0;
static void (*private_pCallBackCTC)(void) = 0;
static uint16 private_ctcCounter;

void TMR0_voidInit(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// Init Timer With Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,TOIE0);
	
#elif TMR0_MODE == TMR0_CTC_MODE
	// Select Mode = CTC Mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// Enable OC Interrupt
	SET_BIT(TIMSK,OCIE0);
	
#elif TMR0_MODE == TMR0_FAST_PWM_MODE
    // Select Mode = FAST PWM Mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

#if TMR0_PWM_ACTION == TMR0_PWM_NON_INVERTING	
	// Select Non Inverting 
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
#elif TMR0_PWM_ACTION == TMR0_PWM_INVERTING
    // Select Inverting 
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#endif
#endif
}


void TMR0_voidStart(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TMR0_voidStop(void)
{
	// Select Prescaler Value = 0
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TMR0_voidSetCompareMatchValue(uint8 Copy_u8CompareValue)
{
	OCR0 = Copy_u8CompareValue;
}


void TMR0_voidetDelay_ms_usingCTC(uint16 Copy_u16Delay_ms)
{
	// under condition tick time 4 MS
	OCR0 = 249;
	private_ctcCounter = Copy_u16Delay_ms;
}


void TMR0_voidSetDytyCycleFastPWM (uint8 Copy_u8DytyCycle)
{
	if(Copy_u8DytyCycle<=100)
	{
		#if TMR0_PWM_ACTION == TMR0_PWM_NON_INVERTING	
		OCR0 = (((uint16)Copy_u8DytyCycle*256)/100)-1;
		#elif TMR0_PWM_ACTION == TMR0_PWM_INVERTING
		Copy_u8DytyCycle = 100 - Copy_u8DytyCycle;
		OCR0 = (((uint16)Copy_u8DytyCycle*256)/100)-1;
		#endif	
	}
}


void TMR0_voidSetCallBackOVF(void(*ptrToFun)(void))
{
	if(ptrToFun != 0)
	{
		private_pCallBackOVF = ptrToFun;
	}
}

void TMR0_voidSetCallBackCTC(void(*ptrToFun)(void))
{
	if(ptrToFun != 0)
	{
		private_pCallBackCTC = ptrToFun;
	}
}


void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static uint16 ovfCounter = 0;
	ovfCounter++;
	
	if(TMR0_OVER_FLOW_COUNTER == ovfCounter)
	{
		// Set Preload Value
		TCNT0 = TMR0_PRELOAD_VALUE;
		
		// Clear Counter
		ovfCounter = 0;
		
		// Call Action
		if(private_pCallBackOVF != 0)
		{
			private_pCallBackOVF();
		}
	}
}


void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static uint16 ctcCounter = 0;
	ctcCounter++;
	
	if(private_ctcCounter == ctcCounter)
	{
		// Clear Counter
		ctcCounter = 0;
		
		// Call Action
		if(private_pCallBackCTC != 0)
		{
			private_pCallBackCTC();
		}
	}
}