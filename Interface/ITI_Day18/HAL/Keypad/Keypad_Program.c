/*
 * Keypad_Program.c
 *
 *  Created on: Jul 21, 2025
 *      Author: abdlr
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_Interface.h"

#include <util/delay.h>

#include "HAL/Keypad/Keypad_Interface.h"
#include "HAL/Keypad/Keypad_Private.h"
#include "HAL/Keypad/Keypad_Cfg.h"

u8 KeypadMap[ROWs_NO][COLs_NO]={
						{7,8,9,'/'},
						{4,5,6,'*'},
						{1,2,3,'-'},
						{'C',0,'=','#'}
					  };


u8 Keypad_Init()
{
	MDIO_vSetPortDir(KEYPAD_PORT , 0xF0);
	MDIO_vSetPortVal(KEYPAD_PORT , 0xFF);
}

u8 KeypadGetKey()
{
	for(u8 Col=0; Col <COLs_NO; Col++)
	{
		// Set Col Low
		MDIO_vSetPinVal(KEYPAD_PORT,Col+4,DIO_LOW);

		for(u8 Row=0; Row <ROWs_NO; Row++)
		{
			if(MDIO_GetPinVal(KEYPAD_PORT,Row) == 0 )
			{
				_delay_ms(50);
				if(MDIO_GetPinVal(KEYPAD_PORT,Row) == 0)
				{
					while(MDIO_GetPinVal(KEYPAD_PORT,Row) == 0)
					{
						_delay_ms(50);
						return KeypadMap[Row][Col];
						// Polling
					}
				}
//				return KeypadMap[Row][Col];
			}
		}
		// Set Col High
		MDIO_vSetPinVal(KEYPAD_PORT,Col+4,DIO_HIGH);
	}
	return NO_KEY_PRESSED;
}


