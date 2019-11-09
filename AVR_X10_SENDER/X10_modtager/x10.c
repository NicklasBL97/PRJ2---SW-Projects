/*
 * x10.c
 *
 * Created: 05-10-2019 14:38:13
 *  Author: nickl
 */ 
#include "x10.h"

void initX10(){
	DDRB |= 0b10100000;		//making timer0A and timer1A pin an output
	
	//TCCR0A = 0b01000010;	//toggle on compare match and set to CTC mode REDUNDANT: this is done at startBurst() call
	OCR0A = 66;				//Value required for 120kHz output
	
	
	//set all values for the burst timer
	TCCR1A = 0;				//normal mode
	TCCR1B = 0b00000000;	//no prescaler, timer stopped, rest of normal mode
	TIMSK1 |= 1<<0;			//enable overflow interrupts
	
}

//void sendData(int[8]){
	//
//}

void startBurst(){
	TCCR0A = 0b01000010;	//toggle on compare match and set to CTC mode
	TCCR0B = 0b00000001;	//prescaler sættes til ingen prescaling for at starte 120kHz oscilation	f = f_CPU/(2*N*(1+OCR0A) ~ 119,4 kHz)
	burstTimer(1);
}

void stopBurst(){
	TCCR0B = 0b00000000;	//Stop 120kHz oscillation
	TCCR1B = 0b00000000;	//no prescaler, timer stopped
	
	TCCR0A = 0b00000000;	//IMPORTANT: Can't write to the output pin while in CTC mode, so we change to normal mode
	PORTB = PINB & 0b01111111; //default the output to LOW when not bursting
}

void burstTimer(int ms){
		if(ms < 0 || ms >1000)					// default til 1 sek delay
		{
			TCNT1 = 65536 - (62500);
		} else {								// indsæt delay mellem 0 1000 ms
			TCNT1 = 65536 - ((ms/1000.0)*62500);
		}
		TCCR1B = 0b000000100;	//timer started
}

void zeroCrossDetect(){
	
}

void initT4Delay()
{
	TCCR4A = 0;
	TCCR4B = 0b00000000;
	
}

void T4Delay(int ms)
{
	if(ms < 0 || ms >1000)					// default til 1 sek delay
	{
		TCNT4 = 65536 - (62500);
		} else {								// indsæt delay mellem 0 1000 ms
		TCNT4 = 65536 - ((ms/1000.0)*62500);
	}
	
	
	TCCR4B = 0b000000100;
	while((TIFR4 & (1<<0)) == 0){}
	TCCR4B = 0b00000000;
	TIFR4 = 1<<0;
	
}