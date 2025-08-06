/*
 * TIMER_Program.c
 *
 *  Created on: Jul 27, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/TIMER/TIMER_Private.h"
#include "MCAL/TIMER/TIMER_Cfg.h"

static void(*Global_pvOVFIntFunc)(void)= NULL;
static void(*Global_pvCTCIntFunc)(void)= NULL;

void TIMER0_vInit(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER0_MODE == PWM_PHASE_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);


#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

#else

#error "Select The Timer Mode "

#endif
	// Set Prescaler
	TCCR0 &=0b11111000; //Bit Clearing
	TCCR0 |=TIMER0_PRESCALER;

}

u8 TIMER0_u8SetOVFCallBack(void (*pvCallBackFunc)(void))
{
	u8 Local_Status = OK;
	if(pvCallBackFunc != NULL)
	{
		Global_pvOVFIntFunc=pvCallBackFunc;
	}
	else
	{
		Local_Status = NOK;
	}
	return Local_Status;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	Global_pvCTCIntFunc();
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	Global_pvOVFIntFunc();
}

void TIMER0_vSetTimerValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}


void TIMER0_vCTCTimerValue(u8 Copy_u8Value)
{

	OCR0 = Copy_u8Value;
}

void TIMER0_vOVFIntEnableDisable(u8 Copy_u8TIMER0_INT_e )
{
	if(Copy_u8TIMER0_INT_e == ENABLE)
	{
		SET_BIT(TIMSK , TIMSK_TOIE0);
	}
	else
	{
		CLR_BIT(TIMSK , TIMSK_TOIE0);
	}
}
void TIMER0_vCTCIntEnableDisable(u8 Copy_u8TIMER0_INT_e )
{
	if(Copy_u8TIMER0_INT_e == ENABLE)
	{
		SET_BIT(TIMSK , TIMSK_OCIE0);
	}
	else
	{
		CLR_BIT(TIMSK , TIMSK_OCIE0);
	}
}
u8 TIMER0_u8SetCTCCallBack(void (*pvCallBackFunc)(void))
{
	u8 Local_Status=OK;
	if(pvCallBackFunc != NULL)
	{
		Global_pvCTCIntFunc = pvCallBackFunc;
		Local_Status=OK;
	}
	else
	{
		Local_Status =NOK;
	}
	return Local_Status;
}
