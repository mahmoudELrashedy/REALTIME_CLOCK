/*
 * GI_FUNC.c
 *
 * Created: 9/27/2023 5:24:34 PM
 *  Author: M
 */ 

#include "GI_REG.h"
#include "GI_FUNC.h"
#include "BIT_MATH.h"
void GI_VoidEnable (void) 
{
	SET_BIT(SREG,I) ; 
}
void GI_VoidDisable (void) 
{
	CLR_BIT(SREG,I) ;
}