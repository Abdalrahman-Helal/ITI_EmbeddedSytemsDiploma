/*
 * RTOS_Private.h
 *
 *  Created on: Aug 5, 2025
 *      Author: abdlr
 */

#ifndef OS_RTOS_PRIVATE_H_
#define OS_RTOS_PRIVATE_H_


typedef struct
{
	u8 TaskState;
	u16 u16Priodicty ;
	u16 u16FirstDelay;
	void(*pvTaskFun)(void);
}Task_t;

static void RTOS_vScheduler (void);

#define TASK_RESUMED		0
#define TASK_SUSPENDED		1


#endif /* OS_RTOS_PRIVATE_H_ */
