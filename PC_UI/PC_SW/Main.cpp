#include "Mode.h"
#include "PC_display.h"
//#include "PC_input.h"
//#include "PC_styring.h"
//#include "Serial.h"
//#include "UART.h"
#include <iostream>
#include <chrono>
#include <ctime>



int main()
{
	//henter og udskriver tiden fra PC
	auto tid = std::chrono::system_clock::now();
	std::time_t tidnu = std::chrono::system_clock::to_time_t(tid);
	cout << std::ctime(&tidnu);
	// forsøg på at oprette egen tid og sammenligne kommer her.
	struct tm test = { 0 };
	double sec;
	test.tm_hour = 11;
	test.tm_min = 50;
	//test.tm_year = std::chrono::system_clock::

	return 0;
}