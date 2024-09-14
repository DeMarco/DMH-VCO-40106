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

#define F_CPU 1000000UL


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

#define LED_R_Red_ON		PORTB |= _BV(LED_R_Red)
#define LED_R_Red_OFF		PORTB &= ~_BV(LED_R_Red)

#define LED_R_Yellow_ON		PORTB |= _BV(LED_R_Yellow)
#define LED_R_Yellow_OFF	PORTB &= ~_BV(LED_R_Yellow)

#define LED_C_Green_ON		PORTB |= _BV(LED_C_Green)
#define LED_C_Green_OFF		PORTB &= ~_BV(LED_C_Green)

#define LED_L_Yellow_ON		PORTB |= _BV(LED_L_Yellow)
#define LED_L_Yellow_OFF	PORTB &= ~_BV(LED_L_Yellow)

#define LED_L_Red_ON		PORTB |= _BV(LED_L_Red)
#define LED_L_Red_OFF		PORTB &= ~_BV(LED_L_Red)

#define ALL_LEDS_OFF		PORTB &= 0x03

#define SEG_A	PORTD6
#define SEG_B	PORTD5
#define SEG_C	PORTD4
#define SEG_D	PORTD3
#define SEG_E	PORTD2
#define SEG_F	PORTD1
#define SEG_G	PORTD0
#define SEG_DP	PORTA0

#define ALL_SEGS_OFF	PORTD = 0x00

#define OnOff_SWITCH			PORTA1
#define OnOff_SWITCH_STATUS		(PINA & _BV(PINA1))

#define MOSI	PORTB5
#define MISO	PORTB6
#define SCK		PORTB7


/* Note names */

#define	NOTE_Cs	1
#define	NOTE_D	2
#define	NOTE_Ds	3
#define	NOTE_E	4
#define	NOTE_F	5
#define	NOTE_Fs	6
#define	NOTE_G	7
#define	NOTE_Gs	8
#define	NOTE_A	9
#define	NOTE_As	10
#define	NOTE_B	11
#define	NOTE_C	12
#define	NOTE_TOO_LOW	13
#define	NOTE_TOO_HIGH	14


#endif /* DEFINITIONS_H_ */