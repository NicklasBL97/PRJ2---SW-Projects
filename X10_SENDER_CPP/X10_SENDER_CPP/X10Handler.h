/*
 * X10Handler.h
 *
 * Created: 10-11-2019 20:40:31
 *  Author: nickl
 */ 

#include <avr/io.h>

#ifndef X10_H_
#define X10_H_

class X10Handler
{
public:
	X10Handler();
	void startBurst();
	void stopBurst();
	void burstTimer(int ms);
	bool zeroCrossDetect();
	bool sendMode(char bitNumber);
	
private:
	char currentMode_;
	char newMode_;
	char sendCnt;
};
void initT4Delay();
void T4Delay(int ms);

#endif