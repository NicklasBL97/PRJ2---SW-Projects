#include "X10Receiver.h"
X10Receiver::X10Receiver()
{
	DDRB |= 0b10100001;		//making timer0A and timer1A pin an output
	DDRE |= 0b00001000;		//making timer3A an output
	
	EIMSK |=0b00000101;		//Enable INT0 for ZeroCrossDetector
	EICRA |=0b00100010;		//falling edge triggers INT0
	
	//set all values for the correction timer
	TCCR3A = 0;				//normal mode
	TCCR3B = 0b00000000;	//0 prescaler, timer stopped, rest of normal mode
	TIMSK3 |= 1<<0;			//enable overflow interrupts
}



void X10Receiver::correctionTimer(){
	TCNT3 = 60737;	//300 us delay with 64 prescaler and 16Mhz clock
	TCCR3B = 0b0000001;	//timer started prescaler 64
}

void X10Receiver::stopCorrection(){
	TCCR3B = 0b00000000;	//no prescaler, timer stopped
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