/*
 * TIMER_Private.h
 *
 *  Created on: Jul 27, 2025
 *      Author: abdlr
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_


#define TCCR0_FOC0	7
#define TCCR0_WGM00	6
#define TCCR0_COM01	5
#define TCCR0_COM00	4
#define TCCR0_WGM01	3
#define TCCR0_CS02	2
#define TCCR0_CS01	1
#define TCCR0_CS00	0


#define TIMSK_OCIE0	1
#define TIMSK_TOIE0	0

#define TIFR_OCF0	1
#define TIFR_TOV0   0


#define TCCR0  (*((volatile u8 * )0x53))
#define TCNT0  (*((volatile u8 * )0x52))
#define OCR0   (*((volatile u8 * )0x5C))
#define TIMSK  (*((volatile u8 * )0x59))
#define TIFR   (*((volatile u8 * )0x58))

#define TCCR1A (*((volatile u8 * )0x4F))
#define TCCR1B (*((volatile u8 * )0x4E))
#define	TCNT1H (*((volatile u8 * )0x4D))
#define	TCNT1L (*((volatile u8 * )0x4C))
#define TCNT1  (*((volatile u16 * )0x4C))
#define	OCR1AH (*((volatile u8 * )0x4B))
#define OCR1AL (*((volatile u8 * )0x4A))
#define OCR1A   (*((volatile u16 * )0x4B))
#define OCR1BH (*((volatile u8 * )0x49))
#define OCR1BL (*((volatile u8 * )0x48))
#define OCR1B  (*((volatile u16 * )0x48))
#define ICR1H  (*((volatile u8 * )0x47))
#define ICR1L  (*((volatile u8 * )0x46))
#define ICR1   (*((volatile u16 * )0x46))



#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
