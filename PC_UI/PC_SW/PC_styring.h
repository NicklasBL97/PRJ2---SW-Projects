#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "Mode.h"
#include "PC_display.h"
#include "PC_input.h"
#include "UART.h"

class PC_styring
{
private:
	Mode mode_;
	PC_display display_;
	PC_input input_;
	CSerial Uart_;
public:
	PC_styring();
	void SetMode(int);
	void SpoergEfterOpvaagningOenskes();
	void SpoergEfterOpvaagningsTidspunkt();
	void SetOpvaagningsTid(int, int);
	void SpoergEfterNatTidOensket();
	void SpoergEfterNatTidspunkt();
	void SetNatTid(int, int);
	void GetMode();
	void UdskrivModeInfo();
	void UdskrivModeAktiveret();
	void SendKommando(int);
	void SpoergEfterStyringsValg();
	void ToggleValgtStyring(int);
};

