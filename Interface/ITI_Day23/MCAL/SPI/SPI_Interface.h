/*
 * SPI_Interface.h
 *
 *  Created on: Jul 31, 2025
 *      Author: abdlr
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


#define SPI_MASTER_MODE	0
#define SPI_SLAVE_MODE	1


/*
 * Options
 * 1- Master -> SPI_MASTER_MODE
 * 2- Slave -> SPI_SLAVE_MODE
 */

void SPI_vInit(u8 Copy_u8SPIMode);
u8 SPI_u8DataSend(u8 Copy_u8Data);




#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
