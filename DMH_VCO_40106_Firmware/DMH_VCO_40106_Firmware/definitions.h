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


/* CPU Clock */

#define F_CPU 8000000UL


/* Pin functions */

#define SAW_IN			PORTB0
#define COMP_REF		PORTB1

#define LED_Sharp		PORTB2
#define LED_R_Red		PORTB3
#define LED_R_Yellow	PORTB4
#define LED_C_Green		PORTB5
#define LED_L_Yellow	PORTB6
#define LED_L_Red		PORTB7

#define LED_Sharp_ON		PORTB |= _BV(LED_Sharp)
#define LED_Sharp_OFF		PORTB &= ~_BV(LED_Sharp)

#define LED_R_Red_ON	PORTB |= _BV(LED_R_Red)
#define LED_R_Red_OFF	PORTB &= ~_BV(LED_R_Red)

#define LED_R_Yellow_ON		PORTB |= _BV(LED_R_Yellow)
#define LED_R_Yellow_OFF	PORTB &= ~_BV(LED_R_Yellow)

#define LED_C_Green_ON		PORTB |= _BV(LED_C_Green)
#define LED_C_Green_OFF		PORTB &= ~_BV(LED_C_Green)

#define LED_L_Yellow_ON		PORTB |= _BV(LED_L_Yellow)
#define LED_L_Yellow_OFF	PORTB &= ~_BV(LED_L_Yellow)

#define LED_L_Red_ON		PORTB |= _BV(LED_L_Red)
#define LED_L_Red_OFF		PORTB &= ~_BV(LED_L_Red)


#define SEG_A	PORTA1
#define SEG_B	PORTA0
#define SEG_C	PORTD4
#define SEG_D	PORTD3
#define SEG_E	PORTD2
#define SEG_F	PORTD1
#define SEG_G	PORTD0
#define SEG_DP	PORTD5


#define MOSI	PORTB5
#define MISO	PORTB6
#define SCK		PORTB7


/* Note names */

#define	NOTE_C	1
#define	NOTE_Cs	2
#define	NOTE_D	3
#define	NOTE_Ds	4
#define	NOTE_E	5
#define	NOTE_F	6
#define	NOTE_Fs	7
#define	NOTE_G	8
#define	NOTE_Gs	9
#define	NOTE_A	10
#define	NOTE_As	11
#define	NOTE_B	12


#endif /* DEFINITIONS_H_ */