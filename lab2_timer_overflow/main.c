/*
 * lab2_Timer0_overflow.c
 *
 * Created: 9/10/2018 4:37:03 PM
 * Author : longyic
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

int main(void)
{
    DDRD = 0x40;
	TCCR0A = (1 << WGM01);
	OCR0A = 195;
	TIMSK0 = (1 << OCIE0A);
	sei();
	TCCR0B = (1 << CS02) | (1 << CS00);
    while (1) 
    {
    }
}

ISR(TIMER0_COMPA_vect)
{
	extraTime++;
	
	if(extraTime > 100)
	{
		extraTime = 0;
		PORTD ^= (1 << PORTD6);
	}
}

