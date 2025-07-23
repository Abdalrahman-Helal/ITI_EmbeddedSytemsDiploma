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

#define F_CPU 8000000UL

void main(void)
{
	LCD_InitPortDir();
	LCD_Init();
	LCD_SendData('A');
	LCD_SendData('S');
	LCD_GoToXY(1,6);
	LCD_SendString("helal");
	_delay_ms(1000);
	LCD_ClearDisplay();
	while(1)
	{

	}
}

