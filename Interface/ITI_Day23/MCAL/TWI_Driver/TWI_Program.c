/*
 * TWI_Program.c
 *
 *  Created on: Aug 3, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Cfg.h"



void TWI_vMasterInit(void)
{
	// Set the Clock
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);
	TWBR =20;

	// Enable TWI
	SET_BIT(TWCR , TWCR_TWEN);
};
void TWI_vSlaveInit(u8 Copy_u8SlaveAddress)
{
	TWAR = Copy_u8SlaveAddress << 1;

	// Enable TWI
	SET_BIT(TWCR , TWCR_TWEN);
}
u8 TWI_u8StartCondition(void)
{
	u8 Local_u8Error = no_error ;

	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	// Repeat Start Condition
	SET_BIT(TWCR , TWCR_TWSTA);

	// Polling on Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if(TWSR & 0b11111000 == REP_START_ACK)
	{

	}
	else
	{
		Local_u8Error = repeat_start_cond_error;
	}
	return Local_u8Error;
}
u8 TWI_u8RepeatStartCondition(void)
{

}
u8 TWI_u8SendSlaveAddressWrite(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8Error = no_error;

	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	//Clear Start
	CLR_BIT(TWCR , TWCR_TWSTA);
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR , 0);

	// Polling on Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if(TWSR & 0b11111000 == SLAVE_ADD_AND_WR_ACK)
	{

	}
	else
	{
		Local_u8Error = slave_Address_write_error;
	}
	return Local_u8Error;
}

u8 TWI_u8SendSlaveAddressRead(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8Error = no_error;

	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	//Clear Start
	CLR_BIT(TWCR , TWCR_TWSTA);
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR , 0);

	// Polling on Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if(TWSR & 0b11111000 == SLAVE_ADD_AND_RD_ACK)
	{

	}
	else
	{
		Local_u8Error = slave_Address_read_error;
	}
	return Local_u8Error;

}
u8 TWI_u8MasterWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Error = no_error;

	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	TWDR = Copy_u8Data;

	// Polling on Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if(TWSR & 0b11111000 == MSTR_WR_BYTE_ACK)
	{

	}
	else
	{
		Local_u8Error = master_write_data_error;
	}
	return Local_u8Error;
}

u8 TWI_u8MasterReadData(u8 * Copy_pu8Data)
{
	u8 Local_u8Error = no_error;

	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	// Polling on Flag
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if(TWSR & 0b11111000 == MSTR_RD_BYTE_WITH_ACK)
	{
		*Copy_pu8Data = TWDR;
	}
	else
	{
		Local_u8Error = master_read_data_error;
	}
	return Local_u8Error;
}
u8 TWI_vStopCondition(void)
{
	// Clear Flag
	SET_BIT(TWCR , TWCR_TWINT);

	// Stop Condition
	SET_BIT(TWCR , TWCR_TWSTO);
}
