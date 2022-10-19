/*
 * timer.c
 *
 * Created: 10/8/2022 4:38:51 PM
 *  Author: Seif
 */ 

#include "timer.h"

void TIMER0_init(void){
	TCCR0 = 0X00; // Normal Mode
}

void TIMER0_delay(uint16_t Tdelay){
	uint16_t NoOverFlow, TimerInitial, OverFlowCount = 0;
	double TmaxDelay, Ttick;
	Ttick = PRESCALAR/FCPU;
	TmaxDelay = Ttick * pow(2, 8);
	if(Tdelay < TmaxDelay){
		TimerInitial = ((int)TmaxDelay - Tdelay)/((int)Ttick);
		NoOverFlow = 1;
	}
	else if(Tdelay == (int)TmaxDelay){
		TimerInitial = 0;
		NoOverFlow = 1;
	}
	else{
		NoOverFlow = ceil((double)Tdelay / TmaxDelay);
		TimerInitial = pow(2, 8) - (((double)Tdelay / Ttick) / NoOverFlow);
	}
	TCNT0 = TimerInitial;
	TCCR0 |= ((1<<2) & 0XB7); // Set 256 prescaler
	
	while(OverFlowCount < NoOverFlow){
		while((TIFR& (1<<0)) == 0); // Busy wait
		TIFR |= (1<<0); // Clear overflow flag
		OverFlowCount++;
	}
	TCCR0 = 0X00;
}