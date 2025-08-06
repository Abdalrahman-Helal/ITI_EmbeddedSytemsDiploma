/*
 * TIMER_Cfg.h
 *
 *  Created on: Jul 27, 2025
 *      Author: abdlr
 */

#ifndef MCAL_TIMER_TIMER_CFG_H_
#define MCAL_TIMER_TIMER_CFG_H_

#define NORMAL_MODE 	0
#define PWM_PHASE_MODE	1
#define CTC_MODE 		2
#define FAST_PWM_MODE	3

#define TIMER0_MODE 	FAST_PWM_MODE

#define PRESCALER_1 		0b001
#define PRESCALER_8			0b010
#define PRESCALER_64		0b011
#define PRESCALER_256		0b100
#define PRESCALER0_1024		0b101

#define TIMER0_PRESCALER 	PRESCALER_8
#define TIMER1_PRESCALER	PRESCALER_64




#endif /* MCAL_TIMER_TIMER_CFG_H_ */
