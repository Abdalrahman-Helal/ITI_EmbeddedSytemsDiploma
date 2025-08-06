/*
 * main.c
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "util/delay.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/WDT/WDT_Interface.h"

#include "HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

	/*ICU*/

//u8 Global_u8ICUFlag=0;
//u16 Global_u16TimeOn=0;
//u16 Global_u16TimeOff=0;

//void main(void)
//{


//	u16 Local_u16DutyCyclie=0;
//	u16 Local_u16Time=0;
//	MDIO_vSetPinDir(DIO_PORTB , PIN3 , DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTD , PIN6 , DIO_INPUT);
//
//	// Duty 40%
//	TIMER0_vInit();
//	TIMER0_vCTCTimerValue(102);
//	TIMER1_vICUInit();
//	GIE_Enable();
//
//	LCD_InitPortDir();
//	LCD_Init();
//
//	while(Global_u8ICUFlag <3); // polling
//
//	Local_u16Time = Global_u16TimeOn + Global_u16TimeOff;
//	Local_u16DutyCyclie=(Global_u16TimeOn*100)/(Local_u16Time);
//
//	LCD_DisplayNumber(Global_u16TimeOn);
//	LCD_DisplayNumber(Global_u16TimeOff);
//	LCD_DisplayNumber(Local_u16DutyCyclie);
//
//	while(1)
//	{
//
//	}
//}
//
//void __vector_6(void) __attribute__((signal));
//void __vector_6(void)
//{
//	static u16 Start = 0 , Read = 0;
//	switch(Global_u8ICUFlag)
//	{
//	case 0:
//		Start = TIMER1_u16ICRRead();
//		TIMER1_vICUSelectingEdge(ICU_FALLING_EDGE);
//		Global_u8ICUFlag++;
//		break;
//	case 1:
//		Read = TIMER1_u16ICRRead();
//		TIMER1_vICUSelectingEdge(ICU_RISING_EDGE);
//		Global_u16TimeOn= Read -Start;
//		Start = Read;
//		Global_u8ICUFlag++;
//		break;
//	case 2:
//		Read = TIMER1_u16ICRRead();
//		Global_u16TimeOff = Read - Start;
//		Global_u8ICUFlag++;
//		break;
//	}
//}


/* ------------- WDT ------------ */
void main(void)
{
	_delay_ms(500);
	MDIO_vSetPinDir(DIO_PORTA, PIN0 ,DIO_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTA,PIN0 , DIO_HIGH);
	WDT_vSleep(WDT_NUM_CYCLE_2048k);
	WDT_vEnable();

	while(1)
	{

	}

}
