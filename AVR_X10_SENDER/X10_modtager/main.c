/*
 * main.c
 *
 * Created: 05-10-2019 14:37:24
 *  Author: nickl
 */ 
#include "avr/interrupt.h"
#include "x10.h"

ISR(TIMER1_OVF_vect)
{
		stopBurst();
}

// husk sei()

int main(){
	sei();
	initX10();
	
	
	while(1){
		T4Delay(1000);
		startBurst();
	}
	
	return 0;
}