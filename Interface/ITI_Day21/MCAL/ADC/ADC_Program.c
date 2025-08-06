/*
 * ADC_Program.c
 *
 *  Created on: Jul 24, 2025
 *      Author: abdlr
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"

static u16 *Global_ptr =0;
static void (*GlobalPtrFunc)(void)=NULL;
static u8 ADC_STATE=IDLE;

void ADC_Init(void)
{
	 // No interrupt
	CLR_BIT(ADCSRA , ADIE);

	// REF -> AVCC
	SET_BIT(ADMUX , REFS0);
	CLR_BIT(ADMUX , REFS1);

	// Set Prescaler -> 128
	SET_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);

	// ADC Enable
	SET_BIT(ADCSRA , ADEN);
}

u16 ADC_StartConvertPolling(u8 Copy_u8Channel)
{
	u16 ADC_read=0;

	ADMUX &=0b11100000;
	ADMUX |=Copy_u8Channel;

	// Start Conversion

	SET_BIT(ADCSRA , ADSC);

	while(GET_BIT(ADCSRA , ADIF) == 0)
	{

	}
	ADC_read = ADCLH;
	SET_BIT(ADCSRA , ADIF);
	return ADC_read;
}

u8 ADC_StartConvertInt(u8 Copy_u8Channel , u16 *pu16Reading , void(*PtrFunc)(void))
{
	u8 Local_u8Error = OK;

	if(ADC_STATE == IDLE)
	{
		if((NULL != pu16Reading)&& (NULL != PtrFunc) );\
		{
			ADC_STATE = BUSY;
			Global_ptr=pu16Reading;
			GlobalPtrFunc = PtrFunc;

			ADMUX &=0b11100000;
			ADMUX |=Copy_u8Channel;
			// Enable ADC Interrupt
			SET_BIT(ADCSRA , ADIE);
			// Start Conversion
			SET_BIT(ADCSRA , ADSC);
		}
	}
	else
	{
		Local_u8Error = NOK;
	}
	return Local_u8Error;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	// Return Reading
	*Global_ptr =ADCLH;

	// exe function
	GlobalPtrFunc();

	//Interrutpt Disable
	CLR_BIT(ADCSRA , ADIE);

	// Change the State
	ADC_STATE = IDLE;



}
