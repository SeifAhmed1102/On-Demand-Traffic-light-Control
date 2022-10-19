/*
 * led.c
 *
 * Created: 10/8/2022 4:41:47 PM
 *  Author: Seif
 */ 

#include "led.h"

void LED_init(uint8_t ledport, uint8_t ledpin){
	DIO_init(ledpin, ledport, OUT); //Led is an output device
}

void LED_on(uint8_t ledport, uint8_t ledpin){
	DIO_write(ledpin, ledport, HIGH); // Turn on Led pin
}

void LED_off(uint8_t ledport, uint8_t ledpin){
	DIO_write(ledpin, ledport, LOW); // Turn off Led pin
}

void LED_toggle(uint8_t ledport, uint8_t ledpin){
	DIO_toggle(ledpin, ledport); // Toggle Led pin
}