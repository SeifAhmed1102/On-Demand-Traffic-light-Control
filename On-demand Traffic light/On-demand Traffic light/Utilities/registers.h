/*
 * registers.h
 *
 * Created: 10/8/2022 4:34:48 PM
 *  Author: Seif
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "standards.h"

//PINS
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7


// Status Register
#define SREG *((volatile uint8_t*)0X5F)


/************************************************************************/
/*                             DIO Registers                            */
/************************************************************************/

// PORTA Registers
#define PORTA *((volatile uint8_t*)0X3B)
#define DDRA *((volatile uint8_t*)0X3A)
#define PINA *((volatile uint8_t*)0X39)

// PORTB Registers
#define PORTB *((volatile uint8_t*)0X38)
#define DDRB *((volatile uint8_t*)0X37)
#define PINB *((volatile uint8_t*)0X36)

// PORTC Registers
#define PORTC *((volatile uint8_t*)0X35)
#define DDRC *((volatile uint8_t*)0X34)
#define PINC *((volatile uint8_t*)0X33)

// PORTD Registers
#define PORTD *((volatile uint8_t*)0X32)
#define DDRD *((volatile uint8_t*)0X31)
#define PIND *((volatile uint8_t*)0X30)

/************************************************************************/
/*                           Timer0 Registers                           */
/************************************************************************/

// Timer0 Registers
#define TCCR0 *((volatile uint8_t*)0X53)
#define TCNT0 *((volatile uint8_t*)0X52)
#define TIFR *((volatile uint8_t*)0X58)


/************************************************************************/
/*                         Interrupt Registers                          */
/************************************************************************/

#define MCUCR *((volatile uint8_t*)0X55)
#define MCUCSR *((volatile uint8_t*)0X54)
#define GICR *((volatile uint8_t*)0X5B)
#define GIFR *((volatile uint8_t*)0X5A)




#endif /* REGISTERS_H_ */