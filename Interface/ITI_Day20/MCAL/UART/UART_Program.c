/*
` * UART_Program.c
 *
 *  Created on: Jul 30, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "MCAL/UART/UART_Interface.h"
#include "MCAL/UART/UART_Private.h"
#include "MCAL/UART/UART_Cfg.h"


void USART_vInit(void)
{

	u8 Local_UCSRC=0;
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_URSEL);

#if USART_MODE == Asynchronous
	CLR_BIT(Local_UCSRC , UCSRC_UBRRH_UMSEL);

#elif	USART_MODE == Synchronous
	SET_BIT(UCSRC_UDRIE , UCSRC_UBRRH_UMSEL);
#else
#warning "Wrong Config of UART_MODE"
#endif

#if USART_PARITY_MODE == EVEN_PARITY
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UPM1);
	CLR_BIT(Local_UCSRC , UCSRC_UBRRH_UMP0);

#elif USART_PARITY_MODE == ODD_PARITY
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UMP1);
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UMP0);
#else
#endif

#if USART_STOP_MODE == STOP_1BIT
	CLR_BIT(Local_UCSRC , UCSRC_UBRRH_USBS);
#elif USART_STOP_MODE == STOP_2BIT
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_USBS);

#else
#endif

	// Set Character Frame Size to 8 bit
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UCSZ0);
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UCSZ1);

	UCSRC_UBRRH = Local_UCSRC;

	// Set Baud Rate 9600
	UBRRL = BAUD_RATE_9600;

	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);

}
void USART_POLL_vSendData(const u8 Data)
{
	// Send 1 Byte of data == 8 Bit
	while(GET_BIT(UCSRA , UCSRA_UDRE) == 0);
	UDR = Data;

}
void USART_POLL_vSendString(const u8* Data)
{
	//	u8 Counter = 0 ;
	//	while(Data[Counter] != '\0')
	//	{
	//		USART_POLL_vSendData(Data[Counter++]);
	//	}

	while(*Data != '\0')
	{
		USART_POLL_vSendData(*Data++);
	}
}
u8 USART_POLL_vReceiveData(void)
{
	while(GET_BIT(UCSRA , UCSRA_RXC) == 0);
	return UDR;

}
void USART_POLL_vReceiveString(u8 Counter , u8* Data)
{
	//	while(Counter--)
	//	{
	//		*Data = USART_POLL_vReceiveData();
	//		Data++;
	//	}

	u8 i=0;
	for(i=0 ;i < Counter;i++)
	{
		Data[i] = USART_POLL_vReceiveData();
	}
}
