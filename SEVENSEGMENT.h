/*
 * SEVENSEGMENT.h
 *
 * Created: 10/25/2023 7:04:23 AM
 *  Author: M
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_
#define F_CPU 8000000UL
#include <util/delay.h>

void Seg_Write (unsigned char pin , unsigned char val) ; 
void Seg_Display (unsigned char pin , unsigned char val) ; 

#endif /* SEVENSEGMENT_H_ */