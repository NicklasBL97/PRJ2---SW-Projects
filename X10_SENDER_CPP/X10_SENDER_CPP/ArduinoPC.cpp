/*
 * ArduinoPC.cpp
 *
 * Created: 03-12-2019 09:07:25
 *  Author: asger
 */ 



#include "ArduinoPC.h"



Kom::Kom()
{
	
	//UART gøres klar til at modtage og sende
	UCSR0A = 0b00100000;
	
	//UART sættes til receiver og transmitter mode.
	UCSR0B = 0b00011000;
	
	
	//UART sættes til 5 databits. 
	
	UCSR0C = 0b00000110;
	
	//Baudrate sættes til 9600
	UBRR0 = 0b01100111;
	

	
	
}

bool Kom::CharReady()
{
	return UCSR0A & (1<<7);
}

char Kom::ReadChar()
{
	
	if ( CharReady())
	{
		return UDR0;
	}
	return 0;
	
}

void Kom::SendChar(char data)
{
	// Wait for transmitter register empty (ready for new character)
	while ((UCSR0A & (1 << 5)) == 0)
	{
	}
	// Then send the character
	UDR0 = data;
}

