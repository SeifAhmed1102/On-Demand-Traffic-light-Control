/*
 * button.h
 *
 * Created: 10/8/2022 4:42:44 PM
 *  Author: Seif
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"

// Pedestrian Button number in Simulation
#define BUTTON_PED_PORT			PORT_D
#define BUTTON_PED_PIN			PIN2

// Button State
#define LOW	0
#define HIGH 1

void BUTTON_init(uint8_t buttonport, uint8_t buttonpin); // Initialize Button

void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t* value); // Reading Button Value (Pressed or not)



#endif /* BUTTON_H_ */