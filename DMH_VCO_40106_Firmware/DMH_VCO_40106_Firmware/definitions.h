/*
 * definitions.h
 *
 * Created: 25/08/2024 21:45:47
 *  Author: Draycon
 */ 


#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

/* General definitions */

#define HIGH		1
#define LOW			0

#define TRUE		1
#define FALSE		0

#define ENABLED		1
#define DISABLED	0

#define output_high(pin)		PORTB |= _BV(pin) //FIX THIS FOR ATtiny4313
#define output_low(pin)			PORTB &= ~_BV(pin)//FIX THIS FOR ATtiny4313


/* CPU Clock */

#define F_CPU 1000000UL


/* Pin functions */

#define SawIn			PORTB0
#define CompRef			PORTB1

#define LED_Sus			PORTB2
#define LED_Flat		PORTD6
#define LED_R_Red		PORTB3
#define LED_R_Yellow	PORTB4
#define LED_C_Green		PORTB5
#define LED_L_Yellow	PORTB6
#define LED_L_Red		PORTB7

#define MOSI	PORTB5
#define MISO	PORTB6
#define SCK		PORTB7


#endif /* DEFINITIONS_H_ */