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


void main(void)
{

	/* the buzzer  */

	//		u16 ADC_READ = 500;
	//		MDIO_vSetPinDir(DIO_PORTD , PIN5 , DIO_OUTPUT);
	//		MDIO_vSetPinDir(DIO_PORTA,PIN0,DIO_INPUT);
	//
	//		//ADC Init
	//		ADC_Init();
	//
	//		//PWM Init
	//		TIMER1_vSetTop(1023);
	//		TIMER1_vSetCTC_A_value(ADC_READ);
	//		TIMER1_vInit();
	//
	//		while(1)
	//		{
	//			ADC_READ = ADC_StartConvertPolling(0);
	//			TIMER1_vSetCTC_A_value(ADC_READ);
	//		}


	// Servo Motor

	MDIO_vSetPinDir(DIO_PORTD , PIN5 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA,PIN0,DIO_INPUT);

	//ADC Init
	ADC_Init();
	TIMER1_vSetTop(20000);
	TIMER1_vInit();

	while(1)
	{
		for(u16 i=400; i<=2600; i++)
		{
			TIMER1_vSetCTC_A_value(i);
			_delay_ms(5);
		}
		_delay_ms(1000);
		for(u16 i=2600; i>=400; i--)
		{
			TIMER1_vSetCTC_A_value(i);
			_delay_ms(5);
		}
	}







}
