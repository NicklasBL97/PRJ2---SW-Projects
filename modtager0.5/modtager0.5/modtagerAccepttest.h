

/*
 * X10Handler.h
 *
 * Created: 10-11-2019 20:40:31
 *  Author: nickl
 */ 

#include <avr/io.h>
#include <stdlib.h>
#ifndef X10_H_
#define X10_H_

using namespace std;

class X10Receiver
{
public:
	X10Receiver();
	void correctionTimer();
	void stopCorrection();
	void countIn();
	int getMaster();
	//int getBit();
	void setMaster();
	int getMaks();
	void setMaks();
	void tjekCode();
	//void tjekCode1();
	int getTal() const;
	void setTal();
	void setBit1();
	void setBit();
	void setBit2();
	//public attributes to access in interrupts
private:
	int master_;
	int bit_[19]; // der kan bruges et bit istedet for int
	int bit1_[19]; //det er et program der gør noget, der kan laves flere bare med det her
	int bit2_[19];
	int maks_;
	int tal_;

};
void initT4Delay();
void T4Delay(int ms);
#endif 
