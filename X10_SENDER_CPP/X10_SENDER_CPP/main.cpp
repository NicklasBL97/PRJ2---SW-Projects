/*
 * X10_SENDER_CPP.cpp
 *
 * Created: 10-11-2019 20:37:01
 * Author : nickl
 */ 
#include "avr/interrupt.h"
#include <avr/io.h>
#include "X10Handler.h"
#include "ArduinoPC.h"

Kom k;
X10Handler x10hand;

ISR(INT0_vect)	//ZeroCross interrupt
{
	x10hand.correctionTimer();
}

ISR(INT2_vect)	//debugging dummy of zerocross interrupt, can be triggered with PRelec shield SW2
{
	x10hand.correctionTimer();
}

ISR(TIMER1_OVF_vect)	//timer overflow interrupt to end burst
{
	x10hand.stopBurst();
}

ISR(TIMER3_OVF_vect)	//timer overflow interrupt to end burst
{
	
	x10hand.stopCorrection();
	x10hand.sendNextBit();
}

int main(void)
{
	sei();
	
	while(1)
	{
		char data = 0;
		data = k.ReadChar();
		if(data > 0 && data < 5)
		{
			while(!x10hand.getDone()){}
					x10hand.sendMode(data);
					k.SendChar(data);
		}
	}
	
	return 0;
}

