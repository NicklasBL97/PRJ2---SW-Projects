#include "X10Handler.h"

X10Handler::X10Handler()
:done_(true),newMode_(0b00000000),sendCnt_(0)
{
	DDRB |= 0b10100001;		//making timer0A and timer1A pin an output
	
	OCR0A = 66;				//Value required for 120kHz output
	
	EIMSK |=0b00000101;		//Enable INT0 for ZeroCrossDetector
	EICRA |=0b00110011;		//Rising edge triggers INT0
	
	//set all values for the burst timer
	TCCR1A = 0;				//normal mode
	TCCR1B = 0b00000000;	//no prescaler, timer stopped, rest of normal mode
	TIMSK1 |= 1<<0;			//enable overflow interrupts
}

void X10Handler::startBurst(){
	EIMSK &= 0b11111110;	//disable further interrupts from zerocross while bursting
	TCCR0A = 0b01000010;	//set to CTC mode and toggle on compare match
	TCCR0B = 0b00000001;	//prescaler sættes til ingen prescaling for at starte 120kHz oscilation	f = f_CPU/(2*N*(1+OCR0A) ~ 119,4 kHz)
	burstTimer(1);
}

void X10Handler::stopBurst(){
	TCCR0B = 0b00000000;	//Stop 120kHz oscillation
	TCCR1B = 0b00000000;	//no prescaler, timer stopped
	
	TCCR0A = 0b00000000;	//IMPORTANT: Can't write to the output pin while in CTC mode, so we change to normal mode
	PORTB = PINB & 0b01111111; //default the output to LOW when not bursting
	EIMSK |=0b00000001;		//Enable INT0 for ZeroCrossDetector again
}

void X10Handler::burstTimer(int ms){
		if(ms < 0 || ms >1000)					// default til 1 sek delay
		{
			TCNT1 = 65536 - (62500);
		} else {								// indsæt delay mellem 0 1000 ms
			TCNT1 = 65536 - ((ms/1000.0)*62500);
		}
		TCCR1B = 0b00000100;	//timer started
}

void X10Handler::sendMode(char bitNumber)
{
	if(done_)	//only allow sending a new mode if already done with sending current mode
	{
		int x10code = 0;				//temp storage for the mode in the x10 protocol
		
		for(int i = 0; i < 8; i++){		//fill x10code with x10protocol
			if(bitNumber & 1<<i){
				x10code |= 2<<i*2;
				}	else {
				x10code |= 1<<i*2;
			}
		}
		
		//assign all values for sending new mode
		newMode_ = x10code;
		sendCnt_ = 0;
		done_ = false;
		
	}
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