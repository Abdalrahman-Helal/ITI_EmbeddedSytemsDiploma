/*
 * main.c
 *
 *  Created on: Jul 17, 2025
 *      Author: Abdalrahman
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../DIO/DIO_Private.h"

#define F_CPU 8000000UL



#define ZERO 	0b01000000
#define ONE 	0b01111001
#define TWO 	0b00100100
#define THREE 	0b00110000
#define FOUR 	0b00011001
#define FIVE 	0b00010010
#define SIX 	0b00000010
#define SEVEN 	0b01111000
#define EIGHT 	0b00000000
#define NINE 	0b00010000

void main(void)
{
	u8 SSD_u8ArrOfNumbers [10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	SET_BIT(DDRA_REG,0);

	u8 i;
	u8 j;
	DDRA_REG=0xFF;
	PORTA_REG=0x00;

	while(1)
	{
		for(j=0; j<10;j++)
		{
			PORTA_REG=SSD_u8ArrOfNumbers[j];

			for(i=0; i<10;i++)
			{
				PORTA_REG=SSD_u8ArrOfNumbers[i];
				_delay_ms(1000);
			}
		}
	}
}


