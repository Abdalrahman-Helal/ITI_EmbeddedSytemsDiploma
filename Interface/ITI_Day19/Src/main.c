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
#include "MCAL/UART/UART_Interface.h"


#define F_CPU 8000000UL


void main(void)
{
	MDIO_vSetPinDir(DIO_PORTD , PIN0 , DIO_INPUT); // PD0 -> Rx
	MDIO_vSetPinDir(DIO_PORTD , PIN1 , DIO_OUTPUT); // PD1 -> Tx

	MDIO_vSetPinDir(DIO_PORTA ,PIN0 , DIO_OUTPUT); // LED1
	MDIO_vSetPinDir(DIO_PORTA ,PIN1 , DIO_OUTPUT);	// LED2


	USART_vInit();
	u8 Reading;



	while(1)
	{
		Reading = USART_POLL_vReceiveData();

		if(Reading == '1')
		{
			MDIO_vTogglePinVal(DIO_PORTA , PIN0 );
		}
		else if(Reading == '2')
		{
			MDIO_vTogglePinVal(DIO_PORTA , PIN1 );
		}

	}
}
