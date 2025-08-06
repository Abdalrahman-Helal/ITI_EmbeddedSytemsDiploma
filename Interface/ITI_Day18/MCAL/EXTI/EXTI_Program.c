/*
 * EXTI_Program.c
 *
 *  Created on: Jul 23, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"

void EXTI_EnableDisable(u8 Copy_u8EXTI_INTNum_e , u8 Copy_u8EXTI_MODE_e)
{
	switch(Copy_u8EXTI_INTNum_e)
	{
	case EXTI_INT_0:
		if(EXTI_ENABLE == Copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR , GICR_INT0);
		}
		else if(EXTI_DISABLE == Copy_u8EXTI_MODE_e)
		{
			CLR_BIT(GICR , GICR_INT0);
		}
		break;


	case EXTI_INT_1:
		if(EXTI_ENABLE == Copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR , GICR_INT1);
		}
		else if(EXTI_DISABLE == Copy_u8EXTI_MODE_e)
		{
			CLR_BIT(GICR , GICR_INT1);
		}
		break;



	case EXTI_INT_2:
		if(EXTI_ENABLE == Copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR , GICR_INT2);
		}
		else if(EXTI_DISABLE == Copy_u8EXTI_MODE_e)
		{
			CLR_BIT(GICR , GICR_INT2);
		}
		break;
	}
}

void EXTI_SetSenstivity(u8 Copy_u8EXTI_INTNum_e , u8 Copy_u8EXTI_SENSTIVITY_e)
{
	switch(Copy_u8EXTI_INTNum_e)
	{
	case EXTI_INT_0:
		switch(Copy_u8EXTI_SENSTIVITY_e)
		{
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;

		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;

		case EXTI_FAILLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;

		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;

		case EXTI_INT_1:
			switch(Copy_u8EXTI_SENSTIVITY_e)
			{
			case EXTI_LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;

			case EXTI_ON_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;

			case EXTI_FAILLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;

			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}
			break;

			case EXTI_INT_2:
				switch(Copy_u8EXTI_SENSTIVITY_e)
				{
				case
				EXTI_FAILLING_EDGE:
					SET_BIT(MCUCSR , MCUCSR_ISC2);
					break;
				case EXTI_RISING_EDGE:
					CLR_BIT(MCUCSR , MCUCSR_ISC2);
					break;
				}
				break;
	}
}

//void __vector_1(void) __attribute__((signal));
//void __vector_1(void)
//{
//	ToggleLED();
//}
