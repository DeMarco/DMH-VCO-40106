/*
 * DMH_VCO_40106_Firmware.c
 *
 * Created: 25/08/2024 20:57:13
 * Author : Draycon
 */ 

#include "definitions.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "Frequency_table_uint16.h"
#include "Frequency_table_float.h"

void delay_s (uint8_t t)
{
	uint8_t i;

	for (i = 0; i < 10*t; i++)
		_delay_ms(100);
}

void init_display (void)
{
	// Switch off all segments except for DP
	PORTA &= ~_BV(SEG_DP);
	PORTD &= 0x00;
	
	// Rotate all segments
	delay_s(150);
	PORTD &= _BV(SEG_F);
	_delay_ms(150);
	PORTD &= _BV(SEG_A);
	_delay_ms(150);
	PORTD &= _BV(SEG_B);
	_delay_ms(150);
	PORTD &= _BV(SEG_C);
	_delay_ms(150);
	PORTD &= _BV(SEG_D);
	_delay_ms(150);
	PORTD &= _BV(SEG_E);
	_delay_ms(150);
	PORTD &= _BV(SEG_G);
	_delay_ms(150);
	PORTD &= ~_BV(SEG_G);
	PORTA |= _BV(SEG_DP);
	_delay_ms(500);
	// Light up all segments
	PORTD &= 0xEF;
	_delay_ms(500);
	// Switch off DP
	PORTA &= ~_BV(SEG_DP);
}

void display_note (uint8_t note)
{
	switch(note)
	{
		case NOTE_C:
			//PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_G);
			PORTD = 0x4E;
			LED_Sharp_OFF;
			break;
			
		case NOTE_Cs:
			//PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_G);
			PORTD = 0x4E;
			LED_Sharp_ON;
			break;
			
		case NOTE_D:
			//PORTD = _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_F);
			PORTD = 0x3D;
			LED_Sharp_OFF;
			break;
			
		case NOTE_Ds:
			//PORTD = _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_F);
			PORTD = 0x3D;
			LED_Sharp_ON;
			break;
			
		case NOTE_E:
			//PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C);
			PORTD = 0x4F;
			LED_Sharp_OFF;
			break;
		
		case NOTE_F:
			//PORTD = _BV(SEG_A) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_D);
			PORTD = 0x47;
			LED_Sharp_OFF;
			break;
			
		case NOTE_Fs:
			//PORTD = _BV(SEG_A) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_D);
			PORTD = 0x47;
			LED_Sharp_ON;
			break;
				
		case NOTE_G:
			//PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B);
			PORTD = 0x5F;
			LED_Sharp_OFF;
			break;
			
		case NOTE_Gs:
			//PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B);
			PORTD = 0x5F;
			LED_Sharp_ON;
			break;
			
		case NOTE_A:
			//PORTD = _BV(SEG_A) | _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_D);
			PORTD = 0x77;
			LED_Sharp_OFF;
			break;
			
		case NOTE_As:
			//PORTD = _BV(SEG_A) | _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_D);
			PORTD = 0x77;
			LED_Sharp_ON;
			break;
			
		case NOTE_B:
			//PORTD = _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_B);
			PORTD = 0x17;
			LED_Sharp_OFF;
			break;
	}
	
}

void ioinit (void)
{
	// Set PA0 as output
	DDRA |= _BV(PORTA0);
	
	// Set PA1 as input
	DDRA &= ~_BV(PORTA1);
	
	// Activate the PA1 pull-up resistor
	PORTA |= _BV(PORTA1);
	
	// Set PB2 to PB7 ports as output, and PB0 and PB1 as input
	DDRB = 0xFC;
	
	// Disable PB0 and PB1 pull-up resistors, so they can be used as Analog Inputs
	PORTB &= ~_BV(PORTB0) & ~_BV(PORTB1);
	
	// Set all PD ports as output
	DDRD = 0xEF;
	
	// Enable Analog Comparator Input Capture
	ACSR |= _BV(ACIC);
	
	// Select Analog Comparator Interrupt on Rising Output Edge
	//ACSR |= _BV(ACIS1) | _BV(ACIS0); //Not needed if I use the Timer/Counter1 Input Capture interrupt
	
	// Enable Analog Comparator Interrupt
	//ACSR |= _BV(ACIE);
	
	// Select Rising Edge for the Timer/Counter1 Input Capture
	TCCR1B |= _BV(ICES1);
	
	// Select clkio/8 as Timer/Counter1 clock source
	/* Since the CPU is clocked at 8 MHz, the timer will increment at 1 MHz.
	This means it will overflow (MAX = 65535) about every ~65.535 ms, or ~15.23 Hz.
	This is lower than note C0, which is 16.35 Hz */
	TCCR1B |= _BV(CS11);
	
	// Enable Timer/Counter1 Overflow interrupt
	//TIMSK |= _BV(TOIE1); //Read and clear flag instead of handling the output
	
	// Enable Timer/Counter1 Input Capture interrupt
	TIMSK |= _BV(ICIE1);
	
	
	
}


int main(void)
{
    
	ioinit();
	init_display();
	
	//uint16_t temp=0;
	float temp=0.0;
	
	//temp = pgm_read_word(&frequency_table[3][4]);
	temp = pgm_read_float(&frequency_table[3][4]);
	
    while (1) 
    {
    }
}

