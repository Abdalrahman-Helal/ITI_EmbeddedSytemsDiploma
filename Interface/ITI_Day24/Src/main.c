/*
 * main.c
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

#include "HAL/LCD/LCD_Interface.h"

#include "OS/FreeRTOS/FreeRTOS.h"
#include "OS/FreeRTOS/task.h"
#include "OS/FreeRTOS/semphr.h"
#include "OS/FreeRTOS/queue.h"

SemaphoreHandle_t xSemaphore;


void Task1(void *pvParameters)
{
	while(1)
	{
		// wait for the semaphore
		if(xSemaphoreTake(xSemaphore,portMAX_DELAY)==pdTRUE)
		{
			LCD_SendString("Button is Pressed");
			while(1);
		}
	}
}


void ISR_Handler(void)
{
	xSemaphoreGive(xSemaphore);
}



void main(void)
{
	MDIO_vSetPinDir(DIO_PORTA , PIN0 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , PIN1 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD , PIN2 , DIO_INPUT);

	LCD_InitPortDir();
	LCD_Init();
	MDIO_vSetPinVal(DIO_PORTD ,PIN2 , DIO_HIGH);
	EXTI_vSetCallBack(EXTI_INT_0 , ISR_Handler);
	EXTI_SetSenstivity(EXTI_INT_0 , EXTI_FAILLING_EDGE);

	// Create Tasks

	xTaskCreate(Task1 , NULL , 100 , NULL , 0, NULL );

	xSemaphore = xSemaphoreCreateBinary();

//	vSemaphoreCreateBinary(xSemaphore);
	xSemaphoreGive(xSemaphore);
	xSemaphoreTake(xSemaphore , portMAX_DELAY);


	EXTI_EnableDisable(EXTI_INT_0 , EXTI_ENABLE );
	GIE_Enable();
	vTaskStartScheduler();

	while(1)
	{

	}
}

