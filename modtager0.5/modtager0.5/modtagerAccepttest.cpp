#define F_CPU 16000000
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "X10Receiver.h"
using namespace std;




X10Receiver::X10Receiver()
{
	//maks_ = 0; 
	//setMaster();
	//setTal(tal);
	//setBit();
	//setBit1();
		//{1,1,1,1,0,0,1,1,0,0,1,0,1,1,0,0,1,1,0}
	DDRB |= 0b10100001;		//making timer0A and timer1A pin an output
	DDRE |= 0b00001000;		//making timer3A an output
	EIMSK |=0b00000101;		//Enable INT0 for ZeroCrossDetector
	EICRA |=0b00100010;		//falling edge triggers INT0
	
	
		//EICRA |= (1<<0);
		//EICRA |= (1<<1);
		//EICRA |= (1<<2);
		//EICRA |= (1<<3);
		//DDRB = 0xFF; det kan vi ikke da det er brugt en gang skal finde en ny port som port K det laves senere
		//PORTB = 0; se oven over.
		DDRF = 0;
		//DDRD = 0; Ved ikke hvor den bruges, skal måske kigge efter det senere
		
		
		DDRK = 0xFF;
		PORTK = 0;
		sei();
	
	

	//set all values for the correction timer
	TCCR3A = 0;				//normal mode
	TCCR3B = 0b00000000;	//0 prescaler, timer stopped, rest of normal mode
	TIMSK3 |= 1<<0;			//enable overflow interrupts

}



void X10Receiver::correctionTimer(){
	TCNT3 = 55937;	//300 us delay with 64 prescaler and 16Mhz clock
	TCCR3B = 0b0000001;	//timer started prescaler 64
}

void X10Receiver::stopCorrection(){
	TCCR3B = 0b00000000;	//no prescaler, timer stopped
	}
	
void X10Receiver::countIn()
{

	if (((PINF & 0b10000000) != 0) || (bit_[0] ==  1 && bit_[1] == 1 && bit_[2] == 1))
	{
	
		if ( master_ > maks_) //her er maks antal bits ganget med 2 + 3
		{
			master_ = 0;
			
		}
		int nextnumber = 0;
		if (((PINF & 0b10000000) != 0))
		{
			nextnumber = 1;
		}
		bit_[master_] = nextnumber; // måske er det ADC0, men det er her inputtet kommer, og det er en A pin.
		master_++;
	
	}
	else
	{
		master_ = 0;
	}

}

//int  X10Receiver::getBit()
//{
	//return *bit;
//}

int X10Receiver::getMaks()
{
	return maks_;	
}
void X10Receiver::setMaks()
{
	
	maks_ = 19;
}

int X10Receiver::getMaster()
{
	return master_;
}
void X10Receiver::setMaster()
{
		
	master_ = 0;
	
}
int X10Receiver::getTal() const
{
	return tal_;
}
void X10Receiver::setTal()
{
	tal_ = 0;

}

void	X10Receiver::tjekCode()
{	
	
	int tal1 = 0;
	int tal2 = 0;
		for (int i = 0; i < maks_; i++)
	{
		if (bit_[i] == bit1_[i])
		{			
			tal1 ++;
		}
		if (bit_[i] == bit2_[i])
		{
			tal2 ++;
		}		
	}
		if (tal1 == 19)
		{
			PORTK = 0xFF;	
		}
		if (tal2 == 19)
		{
			PORTK = 0x00;
		}
	}
	
	
//void X10Receiver::tjekCode1()
//{
		//int tal1 = 0;
		////int tal2 = 0;
		//for (int i = 0; i < maks_; i++)
		//{
			//if (bit_[i] == bit2_[i])
			//{
				//tal1 ++;
			//}
			////if (bit_[i] == bit2_[i])
			////{
			////tal2 ++;
			////}
		//}
		//if (tal1 == 19)
		//{
			//PORTK = 0x00;
		//}
		////if (tal2 == 19)
		////{
		////PORTK = 0x00;
		////}
	//
	//
//}
	//

void X10Receiver::setBit1()
{
	
	//bit1_[19]={1,1,1,1,0,0,1,1,0,0,1,0,1,1,0,0,1,1,0};
	//for (int i = 0; i < 4; i++)
	//{
		//bit1_[i] = 1;
	//}
	//for (int i = 4; i < 6; i++)
	//{		bit1_[i] = 0;
	//}
	//for (int i = 6; i < 8; i++)
	//{
		//bit1_[i]=1;
	//}
	//for (int i = 8; i < 10; i++)
	//{
		//bit1_[i]=0;
	//}
	//bit1_[10]= 1;
	//bit1_[11] = 0;
	//for (int i = 12; i < 14; i++)
	//{
		//bit1_[i]=1;
	//}
	//for (int i = 14; i < 16; i++)
	//{
		//bit1_[i]=0;
	//}
	//for (int i = 16; i < 18; i++)
	//{
		//bit1_[i]=1;
	//}
	//bit1_[18] = 0;
	bit1_[0]=1;
	bit1_[1]=1;
	bit1_[2]=1;
	bit1_[3]=0;
	bit1_[4]=1;
	bit1_[5]=0;
	bit1_[6]=1;
	bit1_[7]=0;
	bit1_[8]=1;
	bit1_[9]=0;
	bit1_[10]=1;
	bit1_[11]=0;
	bit1_[12]=1;
	bit1_[13]=0;
	bit1_[14]=1;
	bit1_[15]=0;
	bit1_[16]=1;
	bit1_[17]=1;
	bit1_[18]=0;
	
}
void X10Receiver::setBit()
{
	for(int i = 0; i< 19; i++)
	{
		bit_[i] = 0;
	}

}
void X10Receiver::setBit2()
{
	//0b00000010
		bit2_[0]=1;
		bit2_[1]=1;
		bit2_[2]=1;
		bit2_[3]=0;
		bit2_[4]=1;
		bit2_[5]=0;
		bit2_[6]=1;
		bit2_[7]=0;
		bit2_[8]=1;
		bit2_[9]=0;
		bit2_[10]=1;
		bit2_[11]=0;
		bit2_[12]=1;
		bit2_[13]=0;
		bit2_[14]=1;
		bit2_[15]=1;
		bit2_[16]=0;
		bit2_[17]=0;
		bit2_[18]=1;
}
	
void initT4Delay()
{
	TCCR4A = 0;
	TCCR4B = 0b00000000;
}

void T4Delay(int ms)
{
	if(ms < 0 || ms >1000)					// default til 1 sek delay
	{
		TCNT4 = 65536 - (62500);
		} else {								// indsæt delay mellem 0 1000 ms
		TCNT4 = 65536 - ((ms/1000.0)*62500);
	}
	TCCR4B = 0b000000100;
	while((TIFR4 & (1<<0)) == 0){}
	TCCR4B = 0b00000000;
	TIFR4 = 1<<0;
}
