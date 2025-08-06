/*
 * WDT_Program.c
 *
 *  Created on: Jul 29, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "MCAL/WDT/WDT_Interface.h"
#include "MCAL/WDT/WDT_Private.h"
#include "MCAL/WDT/WDT_Cfg.h"

void WDT_vEnable(void)
{
	SET_BIT(WDTCR , WDTCR_WDE);
}

void WDT_vDisable(void)
{
	WDTCR = 0b00011000;
	WDTCR = 0;
}

void WDT_vSleep(u8 Copy_u8SleepCycle)
{
	if(Copy_u8SleepCycle < 8)
	{
		WDTCR &=11111000;
		WDTCR |= Copy_u8SleepCycle;

	}
}
