/*
 * ADC_Private.h
 *
 *  Created on: Jul 24, 2025
 *      Author: abdlr
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


#define ADMUX   (*(volatile u8*)0x27)
#define ADCSRA  (*(volatile u8*)0x26)
#define ADCH    (*(volatile u8*)0x25)
#define ADCL    (*(volatile u8*)0x24)

#define ADCLH   (*(volatile u16*)0x24)

#define REFS0 6
#define REFS1 7

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADATE 5
#define ADIF  4
#define ADSC  6
#define ADEN  7

#define IDLE 0
#define BUSY 1


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
