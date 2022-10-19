/*
 * app.h
 *
 * Created: 10/8/2022 4:43:58 PM
 *  Author: Seif
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Interrupt Driver/interrupt.h"
#include "../MCAL/Timer Driver/timer.h"

// Car and Pedestrian Lights
#define RED				0
#define YELLOW_RED		1 // Yellow light going to Red light (Yellow -> Red)
#define YELLOW_GREEN	2 // Yellow light going to Green light (Yellow -> Green)
#define GREEN			3


// Modes
#define NORMAL			0
#define PEDESTRIAN		1

// Interrupt status
#define INTERRUPT_OFF	0
#define INTERRUPT_ON	1


void APP_init(void);

void APP_start(void);



#endif /* APP_H_ */