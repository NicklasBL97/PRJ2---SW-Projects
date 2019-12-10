/*
 * UARTindkapsling.cpp
 *
 * Created: 03-12-2019 08:56:03
 * Author : nogle gange asger
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
		unsigned char data = '0';
		data = com.ReadChar();
		if (data == '1' || data == '2' || data == '3' || data == '4')
		{
			com.SendChar(data);
		}
	}
	return 0;
}
