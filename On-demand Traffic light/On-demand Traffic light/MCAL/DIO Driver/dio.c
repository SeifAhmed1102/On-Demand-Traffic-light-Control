/*
 * dio.c
 *
 * Created: 10/8/2022 4:40:14 PM
 *  Author: Seif
 */ 

#include "dio.h"


void DIO_init(uint8_t pinNumber, uint8_t portNumber, EN_direction_t direction){
	switch(portNumber)
	{
		case PORT_A:
		if(direction == IN){
			CLEAR_BIT(DDRA, pinNumber); // Makes a Pin in PortA Input
		}
		else if(direction == OUT){
			SET_BIT(DDRA, pinNumber); // Makes a Pin in PortA Output
		}
		else{
			// Error handling
		}
		break;
		case PORT_B:
		if(direction == IN){
			CLEAR_BIT(DDRB, pinNumber); // Makes a Pin in PortB Input
		}
		else if(direction == OUT){
			SET_BIT(DDRB, pinNumber); // Makes a Pin in PortB Output
		}
		else{
			// Error handling
		}
		break;
		case PORT_C:
		if(direction == IN){
			CLEAR_BIT(DDRC, pinNumber); // Makes a Pin in PortC Input
		}
		else if(direction == OUT){
			SET_BIT(DDRC, pinNumber); // Makes a Pin in PortC Output
		}
		else{
			// Error handling
		}
		break;
		case PORT_D:
		if(direction == IN){
			CLEAR_BIT(DDRD, pinNumber); // Makes a Pin in PortD Input
		}
		else if(direction == OUT){
			SET_BIT(DDRD, pinNumber); // Makes a Pin in PortD Output
		}
		else{
			// Error handling
		}
		break;
	}
}

void DIO_write(uint8_t pinNumber, uint8_t portNumber, EN_value_t value){
	switch(portNumber)
	{
		case PORT_A:
		if(value == LOW){
			CLEAR_BIT(PORTA, pinNumber); // Write 0 on a Pin in PortA
		}
		else if(value == HIGH){
			SET_BIT(PORTA, pinNumber); // Write 1 on a Pin in PortA
		}
		else{
			// Error handling
		}
		break;
		case PORT_B:
		if(value == LOW){
			CLEAR_BIT(PORTB, pinNumber); // Write 0 on a Pin in PortB
		}
		else if(value == HIGH){
			SET_BIT(PORTB, pinNumber); // Write 1 on a Pin in PortB
		}
		else{
			// Error handling
		}
		break;
		case PORT_C:
		if(value == LOW){
			CLEAR_BIT(PORTC, pinNumber); // Write 0 on a Pin in PortC
		}
		else if(value == HIGH){
			SET_BIT(PORTC, pinNumber); // Write 1 on a Pin in PortC
		}
		else{
			// Error handling
		}
		break;
		case PORT_D:
		if(value == LOW){
			CLEAR_BIT(PORTD, pinNumber); // Write 0 on a Pin in PortD
		}
		else if(value == HIGH){
			SET_BIT(PORTD, pinNumber); // Write 1 on a Pin in PortD
		}
		else{
			// Error handling
		}
		break;
	}
}

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	switch(portNumber)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA, pinNumber); //Toggle a Pin in PortA
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB, pinNumber); //Toggle a Pin in PortB
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC, pinNumber); //Toggle a Pin in PortC
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD, pinNumber); //Toggle a Pin in PortD
		break;
	}
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch(portNumber)
	{
		case PORT_A:
		*value = READ_BIT(PINA, pinNumber); // Read a Pin in PortA
		break;
		case PORT_B:
		*value = READ_BIT(PINB, pinNumber); // Read a Pin in PortB
		break;
		case PORT_C:
		*value = READ_BIT(PINC, pinNumber); // Read a Pin in PortC
		break;
		case PORT_D:
		*value = READ_BIT(PIND, pinNumber); // Read a Pin in PortD
		break;
	}
}