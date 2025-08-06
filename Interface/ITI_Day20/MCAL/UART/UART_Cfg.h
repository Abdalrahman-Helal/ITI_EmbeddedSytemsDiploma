/*
 * UART_Cfg.h
 *
 *  Created on: Jul 30, 2025
 *      Author: abdlr
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_

/*
 * Options
 * 1- Asynchronous
 * 2- Synchronous
 */

#define USART_MODE 	Asynchronous

/*
 * Options
 * 1- EVEN_PARITY
 * 2- ODD_PARITY
 */

#define USART_PARITY_MODE	EVEN_PARITY


/*
 * Options
 * 1- STOP_1BIT
 * 2- STOP_2BIT
 */

#define USART_STOP_MODE		STOP_1BIT


#endif /* MCAL_UART_UART_CFG_H_ */
