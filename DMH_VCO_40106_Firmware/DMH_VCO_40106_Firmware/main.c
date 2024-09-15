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
#include <avr/pgmspace.h>
#include <util/delay.h>
//#include "Frequency_table_uint16.h"
#include "Frequency_table_float.h"

//////// GLOBAL VARIABLES ////////

uint16_t event_timestamp = 0;



/////// FUNCTIONS /////////

void init_display (void)
{
	// Switch off all segments
	PORTA &= ~_BV(SEG_DP);
	ALL_SEGS_OFF;
	
	// Rotate all segments and LEDs
	_delay_ms(150);
	PORTD |= _BV(SEG_F);
	_delay_ms(150);
	PORTD |= _BV(SEG_A);
	_delay_ms(150);
	PORTD |= _BV(SEG_B);
	_delay_ms(150);
	PORTD |= _BV(SEG_C);
	_delay_ms(150);
	PORTD |= _BV(SEG_D);
	_delay_ms(150);
	PORTD |= _BV(SEG_E);
	_delay_ms(150);
	PORTD |= _BV(SEG_G);
	_delay_ms(150);
	PORTA |= _BV(SEG_DP);
	_delay_ms(150);
	LED_Sharp_ON;
	_delay_ms(150);
	LED_L_Red_ON;
	_delay_ms(150);
	LED_L_Yellow_ON;
	_delay_ms(150);
	LED_C_Green_ON;
	_delay_ms(150);
	LED_R_Yellow_ON;
	_delay_ms(150);
	LED_R_Red_ON;
	_delay_ms(1000);
	// Switch off all segments
	ALL_SEGS_OFF;
	// Switch off all LEDs
	ALL_LEDS_OFF;
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
			//PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_G) & ~_BV(SEG_B);
			PORTD = 0x5E;
			LED_Sharp_OFF;
			break;
			
		case NOTE_Gs:
			//PORTD = _BV(SEG_A) | _BV(SEG_C) | _BV(SEG_D) | _BV(SEG_E) | _BV(SEG_F) & ~_BV(SEG_G) & ~_BV(SEG_B);
			PORTD = 0x5E;
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
			PORTD = 0x1F;
			LED_Sharp_OFF;
			break;
			
		case NOTE_TOO_LOW:
			PORTD = 0x08;
			LED_Sharp_OFF;
			break;
		
		case NOTE_TOO_HIGH:
			PORTD = 0x40;
			LED_Sharp_OFF;
			break;
		
		default:
			PORTD = 0x48;
			LED_Sharp_OFF;
			break;
	}
	
}

void calculate_note (uint16_t timestamp)
{
	float freq = 0.0;
	float period_us = 0.0;
	uint8_t i, j;
	uint8_t note_number;
	
	// Convert timestamp into wave frequency
	period_us = timestamp / 1000.0;
	period_us = period_us / 1000.0;
	freq = 1.0 / period_us;
	
	// Check if frequency is within usable range
	if(freq < pgm_read_float(&frequency_table[NOTE_MIN][0]))
	//if(freq < pgm_read_float(&frequency_table[48][2]))
	//if(freq < 300.0)
	{
		display_note(NOTE_TOO_LOW);
		ALL_LEDS_OFF;
		return;
	}
	else if(freq >= pgm_read_float(&frequency_table[NOTE_MAX][0]))
	//else if(freq >= pgm_read_float(&frequency_table[88][4]))
	//else if(freq >= 300.0)
	{
		display_note(NOTE_TOO_HIGH);
		ALL_LEDS_OFF;
		return;
	}
	
	// Check which octave the frequency belongs to
	i = 1;
	while(!(((freq >= pgm_read_float(&frequency_table[i][0]))) && (freq < pgm_read_float(&frequency_table[i+12][0]))))
	{
		i+=12; // Go to the next octave
	}
	
	// Check which note region the frequency belongs to
	note_number = 1;
	while(!(((freq >= pgm_read_float(&frequency_table[i][0]))) && (freq < pgm_read_float(&frequency_table[i+1][0]))))
	{
		i++;
		note_number++;
	}
	
	// Check which accuracy level the frequency belongs to
	j = 0;
	while(!(((freq >= pgm_read_float(&frequency_table[i][j]))) && (freq < pgm_read_float(&frequency_table[i][j+1]))))
	{
		j++;
		if(j==4)
			break;
	}

	// Display note and accuracy LED
	display_note(note_number);
	ACCURACY_LEDS_OFF;	
	switch(j)
	{
		case 0:
			LED_L_Red_ON;
			break;
		case 1:
			LED_L_Yellow_ON;
			break;
		case 2:
			LED_C_Green_ON;
			break;
		case 3:
			LED_R_Yellow_ON;
			break;
		case 4:
			LED_R_Red_ON;
			break;
		default:
			ACCURACY_LEDS_ON;
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
	DDRD = 0xFF;
	
	// Enable Analog Comparator Input Capture
	ACSR |= _BV(ACIC);
	
	// Select Analog Comparator Interrupt on Rising Output Edge
	//ACSR |= _BV(ACIS1) | _BV(ACIS0); //Not needed if I use the Timer/Counter1 Input Capture interrupt
	
	// Enable Analog Comparator Interrupt
	//ACSR |= _BV(ACIE);
	
	//Select clkio/1024 as Timer/Counter0 clock source
	/* With the CPU running at 8 MHz, this will result in timer overflow at ~30,5 Hz rate.
	Don't need to update the display more frequently than this. */
	TCCR0B |= _BV(CS00) | _BV(CS02);
	
	// Enable Timer/Counter0 Overflow interrupt
	TIMSK |= _BV(TOIE0);
	
	// Select Rising Edge for the Timer/Counter1 Input Capture
	TCCR1B |= _BV(ICES1);
	
	// Enable filter for the Timer/Counter1 Input Capture
	TCCR1B |= _BV(ICNC1);
	
	// Select clkio/8 as Timer/Counter1 clock source
	/* Since the CPU is clocked at 8 MHz, the timer will increment at 1 MHz.
	This means it will overflow (MAX = 65535) about every ~65.535 ms, or ~15.23 Hz.
	This is lower than note C0, which is 16.35 Hz */
	TCCR1B |= _BV(CS11);
	
	// Enable Timer/Counter1 Input Capture interrupt
	TIMSK |= _BV(ICIE1);
	
	// Enable Timer/Counter1 Overflow interrupt
	//TIMSK |= _BV(TOIE1);
}


ISR(TIMER0_OVF_vect)
{
	uint16_t buffered_timestamp = 0;
	
	sei(); //To allow nested interrupt handling
	
	if(OnOff_SWITCH_STATUS)
	{
		// Buffer event time stamp
		buffered_timestamp = event_timestamp;
		//buffered_timestamp = 1000;
		
		// Calculate note to be displayed
		calculate_note(buffered_timestamp);	
		//calculate_note(2000);	
		
		//LED_C_Green_OFF;	
	}
	else
	{
		// Switch off all display segments
		ALL_SEGS_OFF;
		
		// Switch off all LEDs
		ALL_LEDS_OFF;
		//LED_C_Green_ON;
	}
	
}

ISR(TIMER1_CAPT_vect)
{
	// Reset Timer1 quickly
	TCNT1 = 0x0000;

	
	// Check if Timer1 overflowed
	if(TIFR & _BV(TOV1))
	{
		PINA |= _BV(PINA0);
		
		// Force frequency calculation to result in 15.26 Hz (lower than C0)
		event_timestamp = 0xFFFF;
		
		// Reset Timer1 overflow flag
		TIFR |= _BV(TOV1);
	}
	else
	{
		// Save event time stamp
		event_timestamp = ICR1;	
		PORTA &= ~_BV(SEG_DP);
	}
	
	//event_timestamp = 1000;	
	//PORTD = 0xFF;
}

/*
ISR(TIMER1_OVF_vect)
{
	static uint8_t count = 0;
	
	count++;
	if(count==15)
	{
		PINA |= _BV(PINA0);
		count=0;
	}
}
*/

int main(void)
{
	
	cli();
	
	ioinit();
	init_display();
	
	sei();
	
    while (1) 
    {
		/*
		_delay_ms(1000);
		PORTA &= ~_BV(SEG_DP);
		_delay_ms(1000);
		PORTA |= _BV(SEG_DP);
		*/
		//ALL_SEGS_OFF;
		//event_timestamp = 2000;
    }
}

