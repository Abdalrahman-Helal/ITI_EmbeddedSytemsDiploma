/*
 * RTOS_Program.c
 *
 *  Created on: Aug 5, 2025
 *      Author: abdlr
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"


#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Cfg.h"

// Global Var
Task_t SystemTask[MAX_NUM_TASK];


void RTOS_vStart(void)
{
	TIMER0_u8SetOVFCallBack(RTOS_vScheduler);
	GIE_Enable();
	TIMER0_vInit();
	TIMER0_vOVFIntEnableDisable(TIMER0_INT_ENABLE);

}

void RTOS_vCreateTask(u8 Copy_u8Priority ,u16 Copy_u16Peridoicty , void (*Copy_pvTaskFun)(void) , u16 Copy_u16FirstDelay)
{
	SystemTask[Copy_u8Priority].u16Priodicty = Copy_u16Peridoicty;
	SystemTask[Copy_u8Priority].pvTaskFun = Copy_pvTaskFun;
	SystemTask[Copy_u8Priority].u16FirstDelay= Copy_u16FirstDelay;
	SystemTask[Copy_u8Priority].TaskState=TASK_RESUMED;

}

static void RTOS_vScheduler(void)
{
	for(u8 Local_Counter=0 ; Local_Counter<MAX_NUM_TASK; Local_Counter++)
	{
		if(SystemTask[Local_Counter].TaskState == TASK_RESUMED)
		{

			if(SystemTask[Local_Counter].u16FirstDelay == 0)
			{
				SystemTask[Local_Counter].pvTaskFun();
				SystemTask[Local_Counter].u16FirstDelay = SystemTask[Local_Counter].u16Priodicty;

			}

			else
			{
				SystemTask[Local_Counter].u16FirstDelay--;
			}
		}

	}
}
void RTOS_vDeleteTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].pvTaskFun = NULL;
}

void RTOS_vResumeTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].TaskState = TASK_RESUMED;
}

void RTOS_vSuspendTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].TaskState = TASK_SUSPENDED;
}


