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



#define F_CPU 8000000UL

void main(void)
{
	u16 Out_Volat = 0;
	u16 Temp =0;
	MDIO_vSetPinDir(DIO_PORTA ,PIN0 , DIO_INPUT);

	MDIO_vSetPinDir(DIO_PORTB , PIN0 ,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN1 ,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN2 ,DIO_OUTPUT);

	MDIO_vSetPinVal(DIO_PORTB , PIN0 , DIO_LOW);
	MDIO_vSetPinVal(DIO_PORTB , PIN1 , DIO_LOW);
	MDIO_vSetPinVal(DIO_PORTB , PIN2 , DIO_LOW);

	ADC_Init();

	while(1)
	{
		Out_Volat= ADC_StartConvertPolling(0b0000);
		Out_Volat =  Out_Volat*(5000/1023);   // 1.0 --> 4.9
		Temp = Out_Volat / 10 ;

		if(Temp < 20)
		{
			MDIO_vSetPinVal(DIO_PORTB,PIN0,DIO_HIGH);
			MDIO_vSetPinVal(DIO_PORTB,PIN1,DIO_LOW);
			MDIO_vSetPinVal(DIO_PORTB,PIN2,DIO_LOW);
		}
		else if(Temp < 40)
		{
			MDIO_vSetPinVal(DIO_PORTB,PIN0,DIO_LOW);
			MDIO_vSetPinVal(DIO_PORTB,PIN1,DIO_HIGH);
			MDIO_vSetPinVal(DIO_PORTB,PIN2,DIO_LOW);
		}
		else
		{
			MDIO_vSetPinVal(DIO_PORTB,PIN0,DIO_LOW);
			MDIO_vSetPinVal(DIO_PORTB,PIN1,DIO_LOW);
			MDIO_vSetPinVal(DIO_PORTB,PIN2,DIO_HIGH);
		}
	}
}
