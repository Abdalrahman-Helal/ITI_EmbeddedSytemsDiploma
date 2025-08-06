/*
 * SPI_Program.c
 *
 *  Created on: Jul 31, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"


void SPI_vInit(u8 Copy_u8SPIMode)
{
	if(Copy_u8SPIMode == SPI_MASTER_MODE)
	{
		// Set in Master Mode
		SET_BIT(SPCR , SPCR_MSTR);

		// Clock Polarity -> Rising
		CLR_BIT(SPCR , SPCR_CPOL);

		// Clock Phase -> Sample
		CLR_BIT(SPCR , SPCR_CPHA);

		// Set Clock Prescaler -> 64
		CLR_BIT(SPCR , SPCR_SPR0);
		SET_BIT(SPCR , SPCR_SPR1);
		CLR_BIT(SPSR , SPSR_SPI2X);

		// SPI  -> Enable
		SET_BIT(SPCR , SPCR_SPE);
	}

	else if(Copy_u8SPIMode == SPI_SLAVE_MODE )
	{
		// Set in Slave Mode
		CLR_BIT( SPCR , SPCR_MSTR);

		// SPI  -> Enable
		SET_BIT(SPCR , SPCR_SPE);
	}
}

u8 SPI_u8DataSendReceive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while(GET_BIT(SPSR , SPSR_SPIF) == 0 );
	return SPDR;
}

