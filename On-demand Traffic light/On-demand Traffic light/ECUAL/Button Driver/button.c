/*
 * button.c
 *
 * Created: 10/8/2022 4:42:58 PM
 *  Author: Seif
 */ 

#include "button.h"

void BUTTON_init(uint8_t buttonport, uint8_t buttonpin){
	DIO_init(buttonpin, buttonport, IN); // Button is an input device
}

void BUTTON_read(uint8_t buttonport, uint8_t buttonpin, uint8_t* value){
	DIO_read(buttonpin, buttonport, value); // Read Button Pin
}