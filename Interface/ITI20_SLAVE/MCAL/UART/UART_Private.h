/*
 * UART_Private.h
 *
 *  Created on: Jul 30, 2025
 *      Author: abdlr
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UDR   (*(volatile u8 *)0x2C)
#define UCSRA (*(volatile u8 *)0x2B)
#define UCSRB (*(volatile u8 *)0x2A)
#define UBRRL (*(volatile u8 *)0x29)
#define UBRRH (*(volatile u8 *)0x40)
#define UCSRC_UBRRH (*(volatile u8 *)0x40)

#define UCSRA_RXC		7
#define UCSRA_TEX		6
#define UCSRA_UDRE		5
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0

#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3


#define UCSRC_UBRRH_URSEL	7
#define UCSRC_UBRRH_UMSEL	6
#define UCSRC_UBRRH_UPM1	5
#define UCSRC_UBRRH_UMP0	4
#define UCSRC_UBRRH_USBS 	3
#define UCSRC_UBRRH_UCSZ1	2
#define UCSRC_UBRRH_UCSZ0	1


#define Asynchronous 	0
#define Synchronous		1

#define EVEN_PARITY		0
#define ODD_PARITY		1


#define STOP_1BIT  		0
#define STOP_2BIT		1

#define FRAME_SIZE_8BIT		0b011

#define BAUD_RATE_9600 	51



#endif /* MCAL_UART_UART_PRIVATE_H_ */
