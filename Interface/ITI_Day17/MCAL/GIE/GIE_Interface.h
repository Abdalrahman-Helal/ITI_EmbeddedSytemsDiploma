/*
 * GIE_Interface.h
 *
 *  Created on: Jul 23, 2025
 *      Author: abdlr
 */

#ifndef MCAL_GIE_GIE_INTERFACE_H_
#define MCAL_GIE_GIE_INTERFACE_H_

typedef enum{
	DISABLE=1,
	ENABLE=1
}Mode_e;

void GIE_Enable(void);
void GIE_Disable(void);


#endif /* MCAL_GIE_GIE_INTERFACE_H_ */
