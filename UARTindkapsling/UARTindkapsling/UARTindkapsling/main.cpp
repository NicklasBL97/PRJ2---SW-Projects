/*
 * UARTindkapsling.cpp
 *
 * Created: 03-12-2019 08:56:03
 * Author : asger
 */ 

#include <avr/io.h>
#include "ArduinoPC.h"


int main(void)
{
	
	kommunikation com;
	DDRB = 0b11111111;

	
    /* Replace with your application code */
	
	
    while (1) 
    {
		
	com.ReadChar();
	
		
	}
	
}
