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

	// clear on compare set on top
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else

#error "Select The Timer Mode "

#endif
	// Set Prescaler
	TCCR0 &=0b11111000; //Bit Clearing
	TCCR0 |=TIMER0_PRESCALER;

}

void TIMER0_vDeinit(void)
{
	TCCR0 = 0;
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

void TIMER1_vInit(void)
{
	// Fast PWM Mode
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	SET_BIT(TCCR1A , TCCR1A_WGM11);
	SET_BIT(TCCR1B , TCCR1B_WGM12);
	SET_BIT(TCCR1B , TCCR1B_WGM13);

	// Set on Top , Clear on CTC
	CLR_BIT(TCCR1A , TCCR1A_COM1A0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);

	// Set Prescaler ->  8
	TCCR1B &=0b11111000;
	TCCR1B|= TIMER1_PRESCALER;

	// Disable INT
	TIMSK &=0b110000011;
}

void TIMER1_vICUInit(void)
{
	// Normal Mode
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	CLR_BIT(TCCR1A , TCCR1A_WGM11);
	CLR_BIT(TCCR1B , TCCR1B_WGM12);
	CLR_BIT(TCCR1B , TCCR1B_WGM13);

	// Noise Cancel;
	SET_BIT(TCCR1B,TCCR1B_ICNC1);

	// Select ICU Edge
	SET_BIT(TCCR1B , TCCR1B_ICES1);

	// ICU Interrupt
	SET_BIT(TIMSK, TIMSK_TICIE1);

	// Set Prescaler ->  8
	TCCR1B &=0b11111000;
	TCCR1B|= TIMER1_PRESCALER;
}

u16 TIMER1_u16ICRRead(void)
{
	return ICR1;
}

void TIMER1_vSetTop(u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue;
}

void TIMER1_vSetCTC_A_value(u16 Copy_u16CTCValue)
{
	OCR1A = Copy_u16CTCValue;
}

void TIMER1_vICUSelectingEdge(u8 Copy_u8EdgeValue)
{
	if(Copy_u8EdgeValue == ICU_RISING_EDGE)
	{
		// Select ICU Rising Edge
		SET_BIT(TCCR1B , TCCR1B_ICES1);
	}
	else
	{
		// Select ICU Falling Edge
		CLR_BIT(TCCR1B , TCCR1B_ICES1);
	}
}

void TIMER1_vICUDeinit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = 0;
}
