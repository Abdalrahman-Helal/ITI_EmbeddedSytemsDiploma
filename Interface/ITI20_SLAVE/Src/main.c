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
#include "MCAL/SPI/SPI_Interface.h"

#include "HAL/LCD/LCD_Interface.h"


#define F_CPU 8000000UL


void main(void)
{

	// Slave
	MDIO_vSetPinDir(DIO_PORTB , PIN4 , DIO_INPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN5 , DIO_INPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN6 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN7 , DIO_INPUT);

	// Init
	LCD_InitPortDir();
	LCD_Init();
	SPI_vInit(SPI_SLAVE_MODE);

	while(1)
	{
		u8 Data = SPI_u8DataSendReceive ('A');
		LCD_SendData(Data);
	}


}
