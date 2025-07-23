/*
 * LCD_Interface.h
 *
 *  Created on: Jul 20, 2025
 *      Author: abdlr
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



#endif /* HAL_LCD_LCD_INTERFACE_H_ */



void LCD_InitPortDir();
void LCD_SendCommand(u8 Command);
void LCD_SendData(u8 Data);

void LCD_SendString(const u8 *String);
void LCD_GoToXY(u8 Row , u8 Col);
void LCD_ClearDisplay(void);

void LCD_Init(void);

