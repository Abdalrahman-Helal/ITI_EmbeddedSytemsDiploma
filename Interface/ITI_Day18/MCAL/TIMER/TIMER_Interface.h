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

#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE 	0

void TIMER0_vInit(void);
void TIMER0_vDeinit(void);
u8 TIMER0_u8SetOVFCallBack(void (*pvCallBackFunc)(void));
void TIMER0_vSetTimerValue(u8 Copy_u8Value);
void TIMER0_vCTCTimerValue(u8 Copy_u8Value);
void TIMER0_vOVFIntEnableDisable(u8 Copy_u8TIMER0_INT_e );
void TIMER0_vCTCIntEnableDisable(u8 Copy_u8TIMER0_INT_e );
u8 TIMER0_u8SetCTCCallBack(void (*pvCallBackFunc)(void));

void TIMER1_vInit(void);
void TIMER1_vICUInit(void);
void TIMER1_vICUDeinit(void);
u16 TIMER1_u16ICRRead(void);
void TIMER1_vSetTop(u16 Copy_u16TopValue);
void TIMER1_vSetCTC_A_value(u16 Copy_u16CTCValue);
void TIMER1_vICUSelectingEdge(u8 Copy_u8EdgeValue);



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
