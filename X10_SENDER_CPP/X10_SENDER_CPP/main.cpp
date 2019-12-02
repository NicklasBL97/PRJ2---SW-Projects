/*
 * X10_SENDER_CPP.cpp
 *
 * Created: 10-11-2019 20:37:01
 * Author : nickl
 */ 
#include "avr/interrupt.h"
#include <avr/io.h>
#include "X10Handler.h"

X10Handler x10hand;

ISR(INT0_vect)	//ZeroCross interrupt
{
	if(!x10hand.done_)	//dont send if already done
	{
		if(x10hand.sendCnt_ < 3)	// send first 3 burst to signal an incoming message to receiver
		{
			x10hand.startBurst();
		}
		else if(x10hand.newMode_ & 1<<(x10hand.sendCnt_-3))		//send one bit at a time starting from MSB, only send burst if bit is high
		{
				x10hand.startBurst();
		}
		
		x10hand.sendCnt_++;
		
		if(x10hand.sendCnt_ > 18)	//if message send change done flag to true, stops furter transmission until new call of sendCode function
			x10hand.done_ = true;
	}
}

ISR(INT2_vect)	//debugging dummy of zerocross interrupt, can be triggered with PRelec shield SW2
{
	if(!x10hand.done_)	//dont send if already done
	{
		if(x10hand.sendCnt_ < 3)	// send first 3 burst to signal an incoming message to receiver
		{
			x10hand.startBurst();
		}
		else if(x10hand.newMode_ & 1<<(x10hand.sendCnt_-3))
		{
			x10hand.startBurst();
		}
		
		x10hand.sendCnt_++;
		
		if(x10hand.sendCnt_ > 18)	//if message send change done flag to true, stops furter transmission until new call of sendCode function
		x10hand.done_ = true;
	}
}

ISR(TIMER1_OVF_vect)	//timer overflow interrupt to end burst
{
	x10hand.stopBurst();
}

int main(void)
{
	sei();
	x10hand.sendMode(0b10101010);
	while(1){}
	
	//while(1){
		//if(x10hand.getZeroCross()){
			//x10hand.startBurst();
			//x10hand.setZeroCross(false);
		//}
	//}
	
	return 0;
}

