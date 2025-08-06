/*
 * RTOS_Interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: abdlr
 */

#ifndef OS_RTOS_INTERFACE_H_
#define OS_RTOS_INTERFACE_H_


void RTOS_vStart(void);
void RTOS_vCreateTask(u8 Copy_Priority ,u16 Copy_u16Peridoicty , void (*Copy_pvTaskFun)(void) , u16 Copy_u16FirstDelay);
void RTOS_vDeleteTask(u8 Copy_Priority);
void RTOS_vResumeTask(u8 Copy_Priority);
void RTOS_vSuspendTask(u8 Copy_Priority);

#endif /* OS_RTOS_INTERFACE_H_ */
