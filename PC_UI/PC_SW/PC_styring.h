#pragma once
#include <iostream>
#include "Mode.h"
#include "PC_display.h"
#include "PC_input.h"
using namespace std;
class PC_styring
{
private:
	Mode mode_;
	PC_display display_;
	PC_input input_;
public:
	PC_styring();
	~PC_styring();
	void SetMode(int);
	void SpoergEfterOpvaagningOenskes();
	void SpoergEfterOpvaagningsTidspunkt();
	void SetOpvaagningsTid(int, int);
	void SpoergEfterNatTidOensket();
	void SetNatTidValg(bool);
	void SpoergEfterNatTidspunkt();
	void SetNatTid(int, int);
	void GetMode();
	void UdskrivModeInfo(string);
	void UdskrivModeAktiveret();
	void SendKommando(int);
	void SpoergEfterStyringsValg();
	void ToggleValgtStyring(int);
};

