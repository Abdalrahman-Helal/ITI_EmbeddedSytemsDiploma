/*
 * main.c
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

#include "OS/FreeRTOS/FreeRTOS.h"
#include "OS/FreeRTOS/task.h"
#include "OS/FreeRTOS/semphr.h"

xSemaphoreHandle xSemaphore;

u8 Global_Flag = 0;


void Task1(void *pvParameters)
{
	u8 Flag = 0;
	while(1)
	{
		if(Flag == 0)
		{
			MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_HIGH);
			Flag = 1;
		}
		else
		{
			MDIO_vSetPinVal(DIO_PORTA , PIN0 , DIO_LOW);
			Flag = 0;
		}
		vTaskDelay(500);
	}

}




void Task2(void *pvParameter)
{
	u8 Flag = 0;
	while(1)
	{
		if(Flag == 0)
		{
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , DIO_HIGH);
			Flag = 1;
		}
		else
		{
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , DIO_LOW);
			Flag = 0;
		}
		vTaskDelay(1000);
	}

}

void Task3(void *pvParameter)
{
	while(1)
	{	if(Global_Flag == 0)
	{
		Global_Flag = 1;
		LCD_SendString("Task 3");
		Global_Flag =0;
		vTaskDelay(1000);
	}
	}

}

void Task4(void *pvParameter)
{

	while(1)
	{
		if(Global_Flag == 0)
		{
			Global_Flag = 1;
			LCD_SendString("Task 4");
			Global_Flag =0;
			vTaskDelay(1000);
		}
	}

}

void Task5(void *pvParameter)
{

	while(1)
	{
		if(xSemaphoreTake(xSemaphore , (TickType_t)portMAX_DELAY) == pdTRUE)
		{
			LCD_SendString("Task 5");
			xSemaphoreGive(xSemaphore);
		}
		vTaskDelay(1000);
	}
}

void Task6(void *pvParameter)
{

	while(1)
	{
		if(xSemaphoreTake(xSemaphore , (TickType_t) portMAX_DELAY) == pdTRUE)
		{
			LCD_SendString("Task 6");
			xSemaphoreGive(xSemaphore);
		}
		vTaskDelay(1000);
	}

}


void main(void)
{

	LCD_InitPortDir();
	LCD_Init();

	// LEDs Init

	MDIO_vSetPinDir(DIO_PORTA , PIN0 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , PIN1 , DIO_OUTPUT);

	// Create Tasks

	//	xTaskCreate(Task1 , NULL , 100 , NULL , 0, NULL );
	//	xTaskCreate(Task2 , NULL , 100 , NULL , 1, NULL );

//	xTaskCreate(Task3 , NULL , 100 , NULL , 1, NULL );
//	xTaskCreate(Task4 , NULL , 100 , NULL , 1, NULL );

	xTaskCreate(Task5 , NULL , 100 , NULL , 1, NULL );
	xTaskCreate(Task6 , NULL , 100 , NULL , 1, NULL );

	vSemaphoreCreateBinary	(xSemaphore);

	// RTOS Start
	vTaskStartScheduler();
	while(1)
	{

	}
}

