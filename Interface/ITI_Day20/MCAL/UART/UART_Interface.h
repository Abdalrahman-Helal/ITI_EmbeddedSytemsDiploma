/*
 * UART_Interface.h
 *
 *  Created on: Jul 30, 2025
 *      Author: abdlr
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void USART_vInit(void);
void USART_POLL_vSendData(const u8 Data);
void USART_POLL_vSendString(const u8* Data);
u8 USART_POLL_vReceiveData(void);
void USART_POLL_vReceiveString(u8 Counter , u8* Data);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
