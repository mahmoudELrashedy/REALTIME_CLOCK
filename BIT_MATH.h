/*
 * BIT_MATH.h
 *
 * Created: 9/27/2023 9:56:29 AM
 *  Author: M
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&= ~(1<<BIT))
#define READ_BIT(REG,BIT) ((REG&(1<<BIT))>>BIT)


#endif /* BIT_MATH_H_ */