/*
 * WDT_Interface.h
 *
 *  Created on: Jul 29, 2025
 *      Author: abdlr
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

#define WDT_NUM_CYCLE_16k		0b000
#define WDT_NUM_CYCLE_32k		0b001
#define WDT_NUM_CYCLE_64k		0b010
#define WDT_NUM_CYCLE_128k		0b011
#define WDT_NUM_CYCLE_256k		0b100
#define WDT_NUM_CYCLE_512k		0b101
#define WDT_NUM_CYCLE_1024k		0b110
#define WDT_NUM_CYCLE_2048k		0b111


void WDT_vEnable(void);
void WDT_vDisable(void);
void WDT_vSleep(u8 Copy_u8SleepCycle);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
