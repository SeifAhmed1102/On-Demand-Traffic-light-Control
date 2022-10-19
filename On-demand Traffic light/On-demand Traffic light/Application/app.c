/*
 * app.c
 *
 * Created: 10/8/2022 4:43:51 PM
 *  Author: Seif
 */ 

#include "app.h"

uint8_t mode = NORMAL;
uint8_t CarLight = GREEN;
uint8_t PedLight = RED;
uint8_t interrupt_status = INTERRUPT_OFF;

void APP_init(void){
	// Car light initialization 
	LED_init(LED_CAR_PORT, LED_CAR_RED_PIN);
	LED_init(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
	LED_init(LED_CAR_PORT, LED_CAR_GREEN_PIN);
	
	// Pedestrian light initialization 
	LED_init(LED_PED_PORT, LED_PED_RED_PIN);
	LED_init(LED_PED_PORT, LED_PED_YELLOW_PIN);
	LED_init(LED_PED_PORT, LED_PED_GREEN_PIN);
	
	// Pedestrian button initialization
	BUTTON_init(BUTTON_PED_PORT, BUTTON_PED_PIN);
	
	// Timer0 initialization
	TIMER0_init();
	
	// External Interrupt INT0 initialization
	sei();
	RISING_EDGE_SETUP_INT0();
	SETUP_INT0();
}

void APP_start(void){
	uint8_t i; // Loop increment variable
	while(1){
		if(mode == NORMAL){
			switch(CarLight){
				case GREEN:
				{
					// Car Lights 
					LED_on(LED_CAR_PORT, LED_CAR_GREEN_PIN);
					LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_off(LED_CAR_PORT, LED_CAR_RED_PIN);
					
					// Pedestrian Lights
					LED_on(LED_PED_PORT, LED_PED_RED_PIN);
					LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
					LED_off(LED_PED_PORT, LED_PED_GREEN_PIN);
					
					for(i = 0; i < 50; i++){
						TIMER0_delay(66); // Loop to delay 5sec
						if(interrupt_status == INTERRUPT_ON){
							break; // When button pressed during the delay loop, it will break out of the loop and go to Pedestrian Mode
						}
					}
					CarLight = YELLOW_RED;
					PedLight = YELLOW_GREEN;
					break;
				}
				case YELLOW_RED:
				{
					for(i = 0; i < 5; i++){ // Toggle Car yellow lights for 5sec, 3 toggles a second for 5 seconds
						LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
						//LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
						TIMER0_delay(265);
						
						LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
						//LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
						TIMER0_delay(265);
						
						LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
						//LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
						TIMER0_delay(265);
						
						if(interrupt_status == INTERRUPT_ON){
							break; // When button pressed during the loop, it will break out of the loop and go to Pedestrian Mode
						}
					}
						PedLight = GREEN;
						CarLight = RED;
						break;
					}
					case RED:
					{
						// Pedestrian Lights
						LED_off(LED_PED_PORT, LED_PED_RED_PIN);
						LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
						LED_on(LED_PED_PORT, LED_PED_GREEN_PIN);
						
						// Car Lights 
						LED_off(LED_CAR_PORT, LED_CAR_GREEN_PIN);
						LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
						LED_on(LED_CAR_PORT, LED_CAR_RED_PIN);
						
						TIMER0_delay(5000); // Delay for 5sec
						
						CarLight = YELLOW_GREEN;
						PedLight = YELLOW_RED;
						break;
					}
					case YELLOW_GREEN:
					{
						for(i = 0; i < 5; i++){ // Toggle Car yellow lights for 5sec, 3 toggles a second for 5 seconds
							LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
							//LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
							TIMER0_delay(265);
							LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
							//LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
							TIMER0_delay(265);
							LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
							//LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
							TIMER0_delay(265);
						}
						PedLight = RED;
						CarLight = GREEN;
						break;
					}
					default:
						CarLight = GREEN;
						PedLight = RED;
						break;
				}
				
			}
			
			// When mode == PEDESTRIAN
			else{
				for(i = 0; i < 5; i++){ // Toggle Car and Pedestrian yellow Lights for 5sec, 3 toggles a second for 5 seconds
					LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
					LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
					LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
				}
				
				// Pedestrian Lights
				LED_on(LED_PED_PORT, LED_PED_GREEN_PIN);
				LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
				LED_off(LED_PED_PORT, LED_PED_RED_PIN);
			
				// Car Lights
				LED_on(LED_CAR_PORT, LED_CAR_RED_PIN);
				LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
				LED_off(LED_CAR_PORT, LED_CAR_GREEN_PIN);
				
				TIMER0_delay(5000); // Delay for 5sec
				
				for(i = 0; i < 5; i++){ // Toggle Car and Pedestrian yellow Lights for 5sec, 3 toggles a second for 5 seconds
					LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
					LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
					LED_on(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
					LED_on(LED_PED_PORT, LED_PED_YELLOW_PIN);
					TIMER0_delay(265);
				}
				// Pedestrian Lights
				LED_on(LED_PED_PORT, LED_PED_RED_PIN);
				LED_off(LED_PED_PORT, LED_PED_GREEN_PIN);
				LED_off(LED_PED_PORT, LED_PED_YELLOW_PIN);
				
				// Car Yellow light OFF
				LED_off(LED_CAR_PORT, LED_CAR_YELLOW_PIN);
				
				mode = NORMAL;
				interrupt_status = INTERRUPT_OFF;
				
				CarLight = GREEN;
				PedLight = RED;
			}
		}
}

ISR(EXT_INT_0){ // When button pressed, this function is executed
	if(interrupt_status == INTERRUPT_OFF){ // If button already pressed, don't execute ISR (This is used for multiple button presses)
		if(CarLight != RED && CarLight != YELLOW_GREEN){ // If the Car Light is Red or Car Light is Yellow going to green, don't execute ISR
			mode = PEDESTRIAN;
			interrupt_status = INTERRUPT_ON;
		}
	}
}