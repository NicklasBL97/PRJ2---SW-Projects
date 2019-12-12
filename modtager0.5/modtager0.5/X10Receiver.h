/*
 * X10Handler.h
 *
 * Created: 10-11-2019 20:40:31
 *  Author: nickl
 */ 

#include <avr/io.h>

#ifndef X10_H_
#define X10_H_

class X10Receiver
{
public:
	X10Receiver();
	void correctionTimer();
	void stopCorrection();
	//public attributes to access in interrupts
private:
	
};
void initT4Delay();
void T4Delay(int ms);

#endif