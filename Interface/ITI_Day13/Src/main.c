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
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/Keypad/Keypad_Interface.h"



#define F_CPU 8000000UL

void main(void)
{
	//	MDIO_vSetPinDir(DIO_PORTA , PIN1, DIO_OUTPUT);
	//	MDIO_vSetPinVal(DIO_PORTA , PIN1 , DIO_LOW);
	//
	//	MDIO_vSetPinDir(DIO_PORTA , PIN2, DIO_OUTPUT);
	//	MDIO_vSetPinVal(DIO_PORTA , PIN2 , DIO_LOW);

	//	MDIO_vSetPinDir(DIO_PORTC , PIN1 , DIO_OUTPUT);

	//	MDIO_vSetPinDir(DIO_PORTD , PIN0 , DIO_OUTPUT);

	MDIO_vSetPinDir(DIO_PORTB ,PIN0 , DIO_OUTPUT);
	MDIO_vSetPortDir(DIO_PORTB,0b00001111);




	while(1)
	{
		MDIO_vSetPinVal(DIO_PORTB,PIN0 ,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,PIN1 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN2 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN3 ,DIO_HIGH);
		_delay_ms(1000);
		MDIO_vSetPinVal(DIO_PORTB,PIN0 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN1 ,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,PIN2 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN3 ,DIO_HIGH);
		_delay_ms(1000);
		MDIO_vSetPinVal(DIO_PORTB,PIN0 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN1 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN2 ,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,PIN3 ,DIO_HIGH);
		_delay_ms(1000);
		MDIO_vSetPinVal(DIO_PORTB,PIN0 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN1 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN2 ,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,PIN3 ,DIO_LOW);
		_delay_ms(1000);
		//		MDIO_vSetPinVal(DIO_PORTD , PIN0 , DIO_OUTPUT);
		//		_delay_ms(1000);
		//		MDIO_vSetPinVal(DIO_PORTD , PIN0 , DIO_LOW);
		//		_delay_ms(1000);

		//		MDIO_vSetPinVal(DIO_PORTC, PIN1 , DIO_HIGH);
		//		_delay_ms(1000);
		//		MDIO_vSetPinVal(DIO_PORTC, PIN1 , DIO_LOW);
		//		_delay_ms(1000);

		//		MDIO_vSetPinVal(DIO_PORTA , PIN1 , DIO_HIGH);
		//		_delay_ms(1000);
		//		MDIO_vSetPinVal(DIO_PORTA , PIN1 , DIO_LOW);
		//		MDIO_vSetPinVal(DIO_PORTA , PIN2 , DIO_HIGH);
		//		_delay_ms(1000);
		//		MDIO_vSetPinVal(DIO_PORTA , PIN2 , DIO_LOW);
	}
}

