#include "X10TxIF.h"
X10TxIF::X10TxIF()
:done_(true),newMode_(0b00000000),sendCnt_(0)
{
	//Init I/O
	DDRB |= 0b10100001;		//making timer0A and timer1A pin an output
	DDRE |= 0b00001000;		//making timer3A an output
	
	//Init burst 
	OCR0A = 66;				//Value required for 120kHz output
	
	//Init zerocross
	EIMSK |=0b00000101;		//Enable INT0 for ZeroCrossDetector
	EICRA |=0b00100010;		//falling edge triggers INT0
	
	//set all values for the burst timer
	TCCR1A = 0;				//normal mode
	TCCR1B = 0b00000000;	//no prescaler, timer stopped, rest of normal mode
	TIMSK1 |= 1<<0;			//enable overflow interrupts
	
	//set all values for the correction timer
	TCCR3A = 0;				//normal mode
	TCCR3B = 0b00000000;	//0 prescaler, timer stopped, rest of normal mode
	TIMSK3 |= 1<<0;			//enable overflow interrupts
}

void X10TxIF::startBurst(){
	EIMSK &= 0b11111110;	//disable further interrupts from zerocross while bursting
	TCCR0A = 0b01000010;	//set to CTC mode and toggle on compare match
	TCCR0B = 0b00000001;	//prescaler sættes til ingen prescaling for at starte 120kHz oscilation	f = f_CPU/(2*N*(1+OCR0A) = ~119,4 kHz)
	burstTimer(1);			//Start timer for when burst is to stop
}

void X10TxIF::stopBurst(){
	TCCR0B = 0b00000000;		//Stop 120kHz oscillation
	TCCR1B = 0b00000000;		//no prescaler, timer stopped
	
	TCCR0A = 0b00000000;		//NOTICE: Can't write to the output pin while in CTC mode, so we change to normal mode
	PORTB = PINB & 0b01111111;	//default the output to LOW when not bursting
	EIMSK |=0b00000001;			//Enable INT0 for ZeroCrossDetector again
}

void X10TxIF::burstTimer(int ms){
		if(ms < 0 || ms >1000)	// default til 1 sek delay
		{
			TCNT1 = 65536 - (62500);
		} else {				// indsæt delay mellem 0 1000 ms
			TCNT1 = 65536 - ((ms/1000.0)*62500);
		}
		TCCR1B = 0b00000100;	//timer started
}

//Timer to adjust the start of a burst to be at the actual zerocross instead of the zerocross signal
void X10TxIF::correctionTimer(){
	TCNT3 = 60737;			//300 us delay with 64 prescaler and 16Mhz clock
	TCCR3B = 0b0000001;		//timer started prescaler 64
}

//stops the correction timer to avoid further interrupts
void X10TxIF::stopCorrection(){
	TCCR3B = 0b00000000;	//no prescaler, timer stopped
}

//This function handles the setup to send a byte of data. Individual bits are sent in the sendNextBit
void X10TxIF::sendMode(char bitNumber)
{
	if(done_)	//only allow sending a new mode if already done with sending current mode
	{
		int x10code = 0;				//temp storage for the mode in the x10 protocol
		
		for(int i = 0; i < 8; i++){		//fill x10code with x10protocol
			if(bitNumber & 1<<i){
				x10code |= 2<<i*2;
				}	else {
				x10code |= 1<<i*2;
			}
		}
		
		//assign all values for sending new mode
		newMode_ = x10code;
		sendCnt_ = 0;
		done_ = false;
		
	}
}

//get function for the bool done
bool X10TxIF::getDone() const {
	return done_;
}

//this function is to be called at an zerocross and handles if there should be send a burst or not
void X10TxIF::sendNextBit(){
	if(!done_)	//dont send if already done
	{
		if(sendCnt_ < 3)	// send first 3 burst to signal an incoming message to receiver
		{
			startBurst();
		}
		else if(newMode_ & 1<<(15 - (sendCnt_-3)))		//send one bit at a time starting from MSB, only send burst if bit is high
		{
			startBurst();
		}
		
		sendCnt_++;
		
		if(sendCnt_ > 18)	//if message send change done flag to true, stops furter transmission until new call of sendCode function
		done_ = true;
	}
}

//debugging delay to use in main program
void initT4Delay()
{
	TCCR4A = 0;
	TCCR4B = 0b00000000;
	
}

//debugging delay to use in main program between 1 ms and 1000 ms
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