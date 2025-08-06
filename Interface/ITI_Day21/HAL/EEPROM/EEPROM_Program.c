/*
 * EEPROM_Program.c
 *
 *  Created on: Aug 3, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "EEPROM_Cfg.h"

#include "util/delay.h"

#include "MCAL/TWI_Driver/TWI_Interface.h"

void EEPROM_vWriteDataByte(u8 Copy_u8Data , u8 Copy_u8Location , u8 Copy_u8BlockNum)
{
	u8 Local_u8SlaveAddress = 0b01010100 | Copy_u8BlockNum ;

	TWI_vMasterInit();
	TWI_u8StartCondition();
	TWI_u8SendSlaveAddressWrite(Local_u8SlaveAddress);
	TWI_u8MasterWriteData(Copy_u8Data);
	TWI_u8MasterWriteData(Copy_u8Location);
	TWI_vStopCondition();
	_delay_ms(10);
}

u8 EEPROM_vReadDataByte(u8 Copy_u8Location , u8 Copy_u8BlockNum)
{
	u8 Local_u8Data=0, Local_u8SlaveAddress = (0b01010100 | Copy_u8BlockNum) ;

	TWI_vMasterInit();
	TWI_u8StartCondition();
	TWI_u8SendSlaveAddressWrite(Local_u8SlaveAddress);
	TWI_u8MasterWriteData(Copy_u8Location);
	TWI_u8StartCondition();
	TWI_u8SendSlaveAddressRead(Local_u8SlaveAddress);
	TWI_u8MasterReadData(&Local_u8Data);
	TWI_vStopCondition();
	return Local_u8Data;
}
