/*
 * dio.h
 *
 * Created: 10/8/2022 4:40:03 PM
 *  Author: Seif
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"


// All internal driver typedefs
// All driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Direction enum
typedef enum EN_direction_t
{
	IN, // IN = 0
	OUT // OUT = 1
}EN_direction_t;

// Value enum
typedef enum EN_value_t
{
	LOW, // LOW = 0
	HIGH // HIGH = 1
}EN_value_t;

// All driver function prototypes

void DIO_init(uint8_t pinNumber, uint8_t portNumber, EN_direction_t direction); // Initialize dio direction

void DIO_write(uint8_t pinNumber, uint8_t portNumber, EN_value_t value); // Write data to dio

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // Toggle dio

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // Read dio





#endif /* DIO_H_ */