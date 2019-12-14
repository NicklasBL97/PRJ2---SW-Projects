/*
 * X10_SENDER_CPP.cpp
 *
 * Created: 10-11-2019 20:37:01
 * Author : nickl
 */ 
#include "avr/interrupt.h"
#include <avr/io.h>
#include "X10TxIF.h"
#include "ArduinoPC.h"

Kom k;
X10TxIF x10;

ISR(INT0_vect)	//ZeroCross interrupt
{
	x10.correctionTimer();
}

ISR(INT2_vect)	//debugging dummy of zerocross interrupt, can be triggered with PRelec shield SW2
{
	x10.correctionTimer();
}

ISR(TIMER1_OVF_vect)	//timer overflow interrupt to end burst
{
	x10.stopBurst();
}

ISR(TIMER3_OVF_vect)	//timer overflow interrupt to end burst
{
	
	x10.stopCorrection();
	x10.sendNextBit();
}

int main(void)
{
	sei();
	while(1){
		if(x10.getDone())
			x10.sendMode(0b10100101);
	}
	//while(1)
	//{
		//char data = 0;
		//data = k.ReadChar();
		//if(data > 0 && data < 5)
		//{
			//while(!x10.getDone()){}
					//x10.sendMode(data);
					//k.SendChar(data);
		//}
	//}
	
	return 0;
}

