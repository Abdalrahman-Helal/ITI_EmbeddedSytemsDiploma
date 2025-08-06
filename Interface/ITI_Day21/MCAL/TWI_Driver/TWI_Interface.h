/*
 * TWI_Interface.h
 *
 *  Created on: Aug 3, 2025
 *      Author: abdlr
 */

#ifndef MCAL_TWI_DRIVER_TWI_INTERFACE_H_
#define MCAL_TWI_DRIVER_TWI_INTERFACE_H_


typedef enum {
	no_error=0,
	start_cond_error,
	repeat_start_cond_error,
	slave_Address_write_error,
	slave_Address_read_error,
	master_write_data_error,
	master_read_data_error,
	stop_cond_error,

}TWI_Status_ty;

void TWI_vMasterInit(void);
void TWI_vSlaveInit(u8 Copy_u8SlaveAddress);
u8 TWI_u8StartCondition(void);
u8 TWI_u8RepeatStartCondition(void);
u8 TWI_u8SendSlaveAddressWrite(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendSlaveAddressRead(u8 Copy_u8SlaveAddress);
u8 TWI_u8MasterWriteData(u8 Copy_u8Data);
u8 TWI_u8MasterReadData(u8 * Copy_pu8Data);
u8 TWI_vStopCondition(void);

#endif /* MCAL_TWI_DRIVER_TWI_INTE
RFACE_H_ */
