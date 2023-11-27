/*
 * EXTI_REG.h
 *
 * Created: 9/27/2023 9:58:48 AM
 *  Author: M
 */ 


#ifndef EXTI_REG_H_
#define EXTI_REG_H_
//General entrrupt control register and bits
#define GICR (*(volatile unsigned char*)0x5B)
#define INT0 6
#define INT1 7
#define INT2 5

//MCU control register and bits (INT0,INT1)
#define MCUCR (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCU control and status register and bits (INT2)
#define MCUCSR (*(volatile unsigned char*)0x54)
#define ISC2 6




#endif /* EXTI_REG_H_ */