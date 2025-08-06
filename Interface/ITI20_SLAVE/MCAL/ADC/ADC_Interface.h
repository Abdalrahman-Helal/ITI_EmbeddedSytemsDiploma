/*
 * ADC_Interface.h
 *
 *  Created on: Jul 24, 2025
 *      Author: abdlr
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

void ADC_Init(void);
u16 ADC_StartConvertPolling(u8 Copy_u8Channel);
u8 ADC_StartConvertInt(u8 Copy_u8Channel , u16 *pu16Reading , void(*PtrFunc)(void));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
