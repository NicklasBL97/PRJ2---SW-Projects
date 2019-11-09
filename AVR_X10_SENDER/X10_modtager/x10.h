/*
 * x10.h
 *
 * Created: 05-10-2019 14:38:07
 *  Author: nickl
 */ 
#include <avr/io.h>

#ifndef X10_H_
#define X10_H_

void initX10();

//void sendData(int[8]);
void startBurst();
void stopBurst();
void burstTimer(int ms);
void zeroCrossDetect();

void T4Delay(int ms);

#endif /* X10_H_ */