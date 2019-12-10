/*
 * ArduinoPC.cpp
 *
 * Created: 03-12-2019 09:07:25
 *  Author: asger
 */ 



#include "ArduinoPC.h"



kommunikation::kommunikation()
{
	
	//UART gøres klar til at modtage og sende
	UCSR0A = 0b00100000;
	
	//UART sættes til receiver og transmitter mode.
	UCSR0B = 0b00011000;
	
	
	//UART sættes til 5 databits. 
	
	UCSR0C = 0x00000000;
	
	//Baudrate sættes til 9600
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
	
		char test = UDR0;
		
		if ( test == 1)
		{
			PORTB &= 0b00000000;
			PORTB |= 0b00000001;
			return 1;
		}
		else if (test == 2)
		{
			PORTB &= 0b00000000;
			PORTB |= 0b00000010;
			return 2;
		}
		else if (test== 3)
		{
			PORTB &= 0b00000000;
			PORTB |= 0b00000011;
			return 3;
		}
		else if (test == 4)
		{
			PORTB &= 0b00000000;
			PORTB |= 0b00000100;
			return 4;
		}
		else
		{
			PORTB &= 0b00000000;
			PORTB |= 0b10000000;
			return 0;
		}
	}
	return 0;
	
}

void kommunikation :: SendChar(char data)
{
	// Wait for transmitter register empty (ready for new character)
	while ((UCSR0A & (1 << 5)) == 0)
	{
	}
	// Then send the character
	UDR0 = data;
}

