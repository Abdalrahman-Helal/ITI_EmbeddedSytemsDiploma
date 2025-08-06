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

#include "OS/RTOS_Interface.h"


void Task1(void)
{
	static Flag=0;

	if(Flag == 0)
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN0, DIO_HIGH);
		Flag = 1;

	}
	else
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN0, DIO_LOW);
		Flag = 0;
	}
}

void Task2(void)
{
	static Flag=0;

	if(Flag == 0)
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN1, DIO_HIGH);
		Flag = 1;
	}
	else
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN1, DIO_LOW);
		Flag = 0;
	}
}

void Task3(void)
{
	static Flag=0;

	if(Flag == 0)
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN2, DIO_HIGH);
		Flag = 1;
	}
	else
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN2, DIO_LOW);
		Flag = 0;
	}
}



#define F_CPU 8000000UL


void main(void)
{
	//LEDs Init
	MDIO_vSetPinDir(DIO_PORTA , PIN0, DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , PIN1, DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , PIN2, DIO_OUTPUT);

	//Create Tasks
	RTOS_vCreateTask(0,1000,Task1,0);
	RTOS_vCreateTask(1,1000,Task2,0);
	RTOS_vCreateTask(2,1000,Task3,0);


	// RTOS Start
	RTOS_vStart();

	while(1)
	{
     _delay_ms(2000);
     RTOS_vSuspendTask(1);
	}
}
