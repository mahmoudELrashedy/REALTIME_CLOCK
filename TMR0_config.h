/*
 * TMR0_config.h
 *
 */ 


#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/* Options FOR TMR0 Mode:
1- TMR0_NORMAL_MODE
2- TMR0_CTC_MODE
3- TMR0_FAST_PWM_MODE
*/
#define TMR0_MODE         TMR0_CTC_MODE            


/* Options FOR PWM Mode:
1- TMR0_PWM_INVERTING
2- TMR0_PWM_NON_INVERTING
*/


//#define TMR0_PWM_ACTION               TMR0_PWM_NON_INVERTING               

#define TMR0_PRELOAD_VALUE             0
#define TMR0_OVER_FLOW_COUNTER         977

#define TMR0_CTC_COUNTER               4500

#endif /* TMR0_CONFIG_H_ */