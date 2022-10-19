/*
 * led.h
 *
 * Created: 10/8/2022 4:41:39 PM
 *  Author: Seif
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"

// Port number in Simulation
#define LED_CAR_PORT			PORT_A
#define LED_PED_PORT			PORT_B

// Pin number in Simulation
#define LED_CAR_RED_PIN			PIN0
#define LED_CAR_YELLOW_PIN		PIN1
#define	LED_CAR_GREEN_PIN		PIN2
#define LED_PED_RED_PIN			PIN0
#define LED_PED_YELLOW_PIN		PIN1
#define LED_PED_GREEN_PIN		PIN2


void LED_init(uint8_t ledport, uint8_t ledpin); //Initialize Led

void LED_on(uint8_t ledport, uint8_t ledpin); // Turn on Led

void LED_off(uint8_t ledport, uint8_t ledpin); // Turn off Led

void LED_toggle(uint8_t ledport, uint8_t ledpin); // Toggle Led



#endif /* LED_H_ */