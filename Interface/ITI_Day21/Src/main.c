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

#include "MCAL/TWI_Driver/TWI_Interface.h"
#include "HAL/EEPROM/EEPROM_Interface.h"




#define F_CPU 8000000UL


void main(void)
{
	u8 local_u8Data = 0;
	MDIO_vSetPinDir(DIO_PORTC , PIN0 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTC , PIN1 , DIO_OUTPUT);

	MDIO_vSetPinDir(DIO_PORTA , PIN0 , DIO_OUTPUT);

	EEPROM_vWriteDataByte(125,0,0);
	local_u8Data = EEPROM_vReadDataByte(0,0);

	if(local_u8Data == 125)
	{
		MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_HIGH);
	}

	while(1)
	{

	}

}
