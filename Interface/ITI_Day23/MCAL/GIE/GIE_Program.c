/*
 * GIE_Program.c
 *
 *  Created on: Jul 23, 2025
 *      Author: abdlr
 */


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Cfg.h"


void GIE_Enable(void)
{
	SET_BIT(SREG , SREG_I);
}
void GIE_Disable(void)
{
	CLR_BIT(SREG , SREG_I);
}

