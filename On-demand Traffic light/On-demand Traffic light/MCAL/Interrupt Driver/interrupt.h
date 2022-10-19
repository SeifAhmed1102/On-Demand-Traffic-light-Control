/*
 * interrupt.h
 *
 * Created: 10/8/2022 4:36:51 PM
 *  Author: Seif
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

// Interrupt Vectors
#define EXT_INT_0 __vector_1

// The MCUCR bits
#define ISC00 0 // INT0 interrupt request
#define ISC01 1 // INT0 interrupt request

// GICR bits
#define INT0 6 // INT0 interrupt bit number


// Interrupt Enable and Disable
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

// Interrupt sense control
#define RISING_EDGE_SETUP_INT0()	MCUCR|=(1<<ISC01)|(1<<ISC00)

#define FALLING_EDGE_SETUP_INT0()	MCUCR=0X02

#define LOW_LEVEL_SETUP_INT0()		MCUCR=0X00


// Enable External interrupt INT0
#define SETUP_INT0()	SET_BIT(GICR,INT0)

//ISR macro like function
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)




#endif /* INTERRUPT_H_ */