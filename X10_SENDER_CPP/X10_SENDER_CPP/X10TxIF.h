/*
 * X10Handler.h
 *
 * Created: 10-11-2019 20:40:31
 *  Author: nickl
 */ 

#include <avr/io.h>

#ifndef X10_H_
#define X10_H_

class X10TxIF
{
public:
	X10TxIF();
	void startBurst();
	void stopBurst();
	void burstTimer(int ms);
	void correctionTimer();
	void stopCorrection();
	void sendMode(char bitNumber);
	bool getDone() const;
	void sendNextBit();
	
	//public attributes to access in interrupts
private:
	bool done_;
	int newMode_;
	char sendCnt_;
};
void initT4Delay();
void T4Delay(int ms);

#endif