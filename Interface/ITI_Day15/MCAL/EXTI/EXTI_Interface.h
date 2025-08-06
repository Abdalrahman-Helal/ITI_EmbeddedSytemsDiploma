/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 23, 2025
 *      Author: abdlr
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum
{
	EXTI_INT_0=0,
	EXTI_INT_1=1,
	EXTI_INT_2=2,
}EXTI_INTNum_e;

typedef enum
{
	EXTI_DISABLE =0,
	EXTI_ENABLE =1
}EXTI_MODE_e;

typedef enum {
	EXTI_LOW_LEVEL =0 ,
	EXTI_ON_CHANGE,
	EXTI_FAILLING_EDGE,
	EXTI_RISING_EDGE
}EXTI_SENSTIVITY_e;

void EXTI_EnableDisable(u8 Copy_u8EXTI_INTNum_e , u8 Copy_u8EXTI_MODE_e);
void EXTI_SetSenstivity(u8 Copy_u8EXTI_INTNum_e , u8 Copy_u8EXTI_SENSTIVITY_e);




#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
