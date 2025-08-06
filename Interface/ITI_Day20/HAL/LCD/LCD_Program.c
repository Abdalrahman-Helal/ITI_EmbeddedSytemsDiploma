/*
 * LCD_Program.c
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Cfg.h"

#include <util/delay.h>


void LCD_InitPortDir()
{
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_RS_PIN , DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_RW_PIN , DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_E_PIN , DIO_OUTPUT);


	MDIO_vSetPortDir(LCD_DATA_PORT,0xFF);
}

void LCD_SendCommand(u8 Command)
{
	// Set RS -> 0
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_LOW);
	// Set RW -> 0
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);

	MDIO_vSetPortVal(LCD_DATA_PORT,Command);

	MDIO_vSetPinVal(LCD_CTRL_PORT ,LCD_E_PIN , DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT ,LCD_E_PIN , DIO_LOW);

}
void LCD_SendData(u8 Data)
{
	// Set RS -> 1
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_HIGH);

	// Set RW -> 0
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);

	MDIO_vSetPortVal(LCD_DATA_PORT,Data);

	MDIO_vSetPinVal(LCD_CTRL_PORT ,LCD_E_PIN , DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT ,LCD_E_PIN , DIO_LOW);
}

void LCD_Init(void)
{
	_delay_ms(40);

	LCD_SendCommand(0b00111000);
	_delay_ms(1);

	LCD_SendCommand(0b00001100);
	_delay_ms(1);

	LCD_SendCommand(0b00000001);
	_delay_ms(2);

	LCD_SendCommand(0b00000110);
	_delay_ms(1);
}

void LCD_SendString(const u8 *String)
{
	u8 Counter=0;
	while(String[Counter] != '\0')
	{
		LCD_SendData(String[Counter]);
		Counter++;
	}
}

void LCD_GoToXY(u8 Row , u8 Col)
{
	u8 Position;
	if(Row == 0 || Row == 1)
	{
		if(Col >= 0 && Col <= 15)
		{
			switch(Row)
			{

			case 0:
				Position=0x00 + Col;
				break;
			case 1:
				Position=0x40 + Col;
				break;
			}
		}
		LCD_SendCommand(128+Position);
	}
}

void LCD_ClearDisplay(void)
{
	LCD_SendCommand(1);
	_delay_ms(2);
}

void LCD_DisplayNumber(u32 Number)
{
	u32 ReversedNum = 1;
	if(Number == 0)
	{
		LCD_SendData('0');
	}

	while(Number != 0)
	{
		ReversedNum = (ReversedNum*10) + (Number %10);
		Number = Number /10;
	}

	while(ReversedNum != 1)
	{
		LCD_SendData( (ReversedNum%10) + 48);
		ReversedNum= ReversedNum/10;
	}
}


