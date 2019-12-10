/*
 * ArduinoPC.h
 *
 * Created: 03-12-2019 09:02:20
 *  Author: asger
 */ 


#ifndef ARDUINOPC_H_
#define ARDUINOPC_H_

#include <avr/io.h>
#include <stdlib.h>


class Kom
 {
	public:
		Kom();
		
		void SendChar(char);
		char ReadChar();
	private:
		bool CharReady();	
	
	
};











#endif /* ARDUINOPC_H_ */