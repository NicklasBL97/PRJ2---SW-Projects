#include "Serial.h"
#include <iostream>
bool sendExample(int port, int baudRate)
{
	char data[4];

	CSerial * s = new CSerial();

	if(!s->Open(port, baudRate))
	{
		std::cout << "Could not open COM" << port << std::endl;
		

		return false;
	}

	
	// Sending a string of 4 characters
	data[0] = 0; 
	data[1] = 0;
	data[2] = 0;
	data[3] = 1; // ASCII CR
	s->SendData(data, 4);

	s->Close();

	delete s;

}