/*
 * modtager0.4.cpp
 *
 * Created: 01-12-2019 14:57:37
 * Author : Andreas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "X10Receiver.h"

X10Receiver rec();

ISR(INT0_vect)	//ZeroCross interrupt
{
	rec.correctionTimer();
}

ISR(TIMER3_OVF_vect)	//timer overflow interrupt to end burst
{
	
	rec.stopCorrection();
}

volatile int tal = 0; // det er et tal som vi bruger til at sammenligne med i interruptet
volatile bool bit1[19] = {1111001100101100110}; // der kan bruges et bit istedet for int
volatile bool bit2[19] = {1111001100101100110}; // det er en funktion vi har her, som skal gøre et eller andet.
//volatile bool bit3[22] = {1110010101010101010101}; // det er en funktion vi har her, som skal gøre et eller andet.
volatile int maks = 19; // skal stilles efter bit gange 2
//volatile bool burst = '0'; // det er fra burstet, og det går højt, når der kommer et burst, og så aflæser vi når der er et zerocross, der er forhåbentlig det før zerocross.

int main(void)
{
	EICRA |= (1<<0);
	EICRA |= (1<<1);
	EICRA |= (1<<2);
	EICRA |= (1<<3);
	DDRB = 0xFF;
	PORTB = 0;
	DDRF = 0;
	DDRD = 0;
    /* Replace with your application code */
    while (1) 
    {
		if (tal == maks)
		{
			//her kan stå noget med at hvis koden er et eller andet skal den gøre noget, og hvis noget andet, så ikke så meget.
		if (bit1 == bit2)
		{
			PORTB = 0xFF;			
		}
		}
    }
}

//der skal være et lukket signal for det her kan passe.
ISR (INT0_vect)
{
		//EICRA &= (1<<2);
		//EICRA &= (1<<3);
		if ((ADC0D & 0b00000001) == 1 || (bit1[0] ==  1 && bit1[1] == 1 && bit1[2] == 1))
			{
				if (tal >= maks) //her er maks antal bits ganget med 2
				{
					tal = 0;
				}
				bit1[tal] = ADC0D; // måske er det ADC0, men det er her inputtet kommer, og det er en A pin.
				tal++;
			}
		else
		{
			tal = 0;			
		}
		//EICRA |= (1<<2);
		//EICRA |= (1<<3);

}

//ISR (INT1_vect)
//{
	//burst = '1'; // der er lige registreret et burst
		
//}