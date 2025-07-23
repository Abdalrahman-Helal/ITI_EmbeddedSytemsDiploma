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



#define F_CPU 8000000UL

void ToggleLED(void);

void main(void)
{
	MDIO_vSetPinDir(DIO_PORTA , PIN0 , DIO_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_HIGH);

	// Pin Config
	MDIO_vSetPinDir(DIO_PORTD , PIN2 , DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD , PIN2 , DIO_HIGH);

	// Pin INT Config
	EXTI_SetSenstivity(EXTI_INT_0 , EXTI_FAILLING_EDGE );

	EXTI_EnableDisable(EXTI_INT_0 , EXTI_ENABLE);
	GIE_Enable();



	//
	while(1)
	{
	}
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	ToggleLED();
}

void ToggleLED(void)
{
	static u8 flag=1;
	if(flag == 1 )
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_LOW);
		flag = 0;
	}
	else
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_HIGH);
		flag =1;
	}
}

