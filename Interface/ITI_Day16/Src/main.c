/*
 * main.c
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "util/delay.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"

#define F_CPU 8000000UL

void ToggleLED(void)
{
	static u8 counter=0;
	counter++;
	if(counter == 3907)
	{
		counter =0;
		MDIO_vTogglePinVal(DIO_PORTA , PIN0);
	}
}

void main(void)
{
	MDIO_vSetPinDir(DIO_PORTA , PIN0 , DIO_OUTPUT);
//	MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_HIGH);
	TIMER0_u8SetOVFCallBack(ToggleLED);
	TIMER0_vInit();
	TIMER0_vSetTimerValue(0);
	TIMER0_vOVFIntEnableDisable(TIMER0_INT_ENABLE);
	GIE_Enable();

	while(1)
	{

	}

}
