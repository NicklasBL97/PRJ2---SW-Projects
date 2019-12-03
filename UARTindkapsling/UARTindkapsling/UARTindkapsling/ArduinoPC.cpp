/*
 * ArduinoPC.cpp
 *
 * Created: 03-12-2019 09:07:25
 *  Author: asger
 */ 



#include "ArduinoPC.h"



kommunikation::kommunikation()
{
	
	//UART s�ttes til receiver og transmitter mode.
	UCSR0B = 0b00011000;
	
	//UART g�res klar til at modtage
	UCSR0A = 0b00100000;
	
	//UART s�ttes til 5 databits. 
	
	UCSR0C = 0x00000000;
	
	//Baudrate s�ttes til 9600
	UBRR0 = 0b01100111;

	
	
}

bool kommunikation::CharReady()
{
	return UCSR0A & (1<<7);
}

char kommunikation::ReadChar()
{
	
	if ( CharReady())
	{
	
	// Then return it
	return UDR0;
	}
	else 
	return 0;
}


