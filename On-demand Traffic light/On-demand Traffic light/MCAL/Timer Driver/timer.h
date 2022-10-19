/*
 * timer.h
 *
 * Created: 10/8/2022 4:38:43 PM
 *  Author: Seif
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include <math.h>

#define PRESCALAR		256.0
#define FCPU			1000.0

void TIMER0_init(void); // Initialize Timer0

void TIMER0_delay(uint16_t Tdelay); // Delay given the Tdelay 


#endif /* TIMER_H_ */