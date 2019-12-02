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

ISR(INT0_vect)
{
	//toggle led her
	x10hand.setZeroCross(true);
}

ISR(TIMER1_OVF_vect)
{
	x10hand.stopBurst();
}

int main(void)
{
	sei();
	
	while(1){
	T4Delay(1000);
	x10hand.sendMode(0b10101010);
	}
	
	//while(1){
		//if(x10hand.getZeroCross()){
			//x10hand.startBurst();
			//x10hand.setZeroCross(false);
		//}
	//}
	
	return 0;
}

