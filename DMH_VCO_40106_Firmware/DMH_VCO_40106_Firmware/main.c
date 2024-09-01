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
			PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_G);
			LED_Sharp_OFF;
			break;
			
		case NOTE_Cs:
			PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_G);
			LED_Sharp_ON;
			break;
			
		case NOTE_D:
			PORTD = _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_F);
			LED_Sharp_OFF;
			break;
			
		case NOTE_Ds:
			PORTD = _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_F);
			LED_Sharp_ON;
			break;
			
		case NOTE_E:
			PORTD = _BV(SEG_A) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C);
			LED_Sharp_OFF;
			break;
		
		case NOTE_F:
			PORTD = _BV(SEG_A) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_D);	
			LED_Sharp_OFF;
			break;
			
		case NOTE_Fs:
			PORTD = _BV(SEG_A) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B) & ~_BV(SEG_C) & ~_BV(SEG_D);
			LED_Sharp_ON;
			break;
				
		case NOTE_G:
			PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B);
			LED_Sharp_OFF;
			break;
			
		case NOTE_Gs:
			PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_B);
			LED_Sharp_ON;
			break;
			
		case NOTE_A:
			PORTD = _BV(SEG_A) | _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_D);
			LED_Sharp_OFF;
			break;
			
		case NOTE_As:
			PORTD = _BV(SEG_A) | _BV(SEG_B) | _BV(SEG_C) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_D);
			LED_Sharp_ON;
			break;
			
		case NOTE_B:
			PORTD = _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) | _BV(SEG_G) & ~_BV(SEG_A) & ~_BV(SEG_B);
			LED_Sharp_OFF;
			break;
	}
	
}

void ioinit (void)
{
	DDRA = _BV()
	
	
}


int main(void)
{
    
	
	init_display();
	
    while (1) 
    {
    }
}

