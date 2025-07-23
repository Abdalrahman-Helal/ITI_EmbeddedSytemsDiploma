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
#include "HAL/SSD/SSD_Interface.h"

#define ZERO 	0b01000000
#define ONE 	0b01111001
#define TWO 	0b00100100
#define THREE 	0b00110000
#define FOUR 	0b00011001
#define FIVE 	0b00010010
#define SIX 	0b00000010
#define SEVEN 	0b01111000
#define EIGHT 	0b00000000
#define NINE 	0b00010000

#define F_CPU 8000000UL

void main(void)
{

	u8 arr[]={ZERO, ONE , TWO , THREE , FOUR , FIVE ,SIX , SEVEN , EIGHT , NINE};
	LCD_InitPortDir();
	LCD_Init();
	Keypad_Init();
	HSSD_vInit(DIO_PORTB);
//	LCD_SendData('A');
//	LCD_SendData('S');

//	LCD_SendString("helal");
//	_delay_ms(1000);
//	LCD_ClearDisplay();
//	LCD_GoToXY(1,6);
	while(1)
	{
		u8 key=KeypadGetKey();
		if(key != 255 )
		{

			LCD_SendData(key);
			HSSD_vDisplayNumber(DIO_PORTB,arr[key]);
			_delay_ms(50);
		}
	}
}

