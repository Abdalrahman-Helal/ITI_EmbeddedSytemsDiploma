/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 3, 2025
 *      Author: abdlr
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_vWriteDataByte(u8 Copy_u8Data , u8 Copy_u8Location , u8 Copy_u8BlockNum);
u8 EEPROM_vReadDataByte(u8 Copy_u8Location , u8 Copy_u8BlockNum);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
