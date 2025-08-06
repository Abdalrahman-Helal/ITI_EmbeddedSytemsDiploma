/*
 * TIMER_Interface.h
 *
 *  Created on: Jul 27, 2025
 *      Author: abdlr
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum
{
	TIMER0_INT_DISABLE =0,
	TIMER0_INT_ENABLE
}TIMER0_INT_e;


void TIMER0_vInit(void);
u8 TIMER0_u8SetOVFCallBack(void (*pvCallBackFunc)(void));
void TIMER0_vSetTimerValue(u8 Copy_u8Value);
void TIMER0_vCTCTimerValue(u8 Copy_u8Value);
void TIMER0_vOVFIntEnableDisable(u8 Copy_u8TIMER0_INT_e );
void TIMER0_vCTCIntEnableDisable(u8 Copy_u8TIMER0_INT_e );
u8 TIMER0_u8SetCTCCallBack(void (*pvCallBackFunc)(void));

void TIMER1_vInit(void);
void TIMER1_vSetTop(u16 Copy_u16TopValue);
void TIMER1_vSetCTC_A_value(u16 Copy_u16CTCValue);



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
