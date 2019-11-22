/*#pragma once
#include <iostream>
using namespace std;
class PC_styring
{

public:
	PC_styring();
	~PC_styring();
	void SetMode(int);
	void SpoergEfterOpvaagningOenskes();
	void SpoergEfterValgAfMode();
	void SetOpvaagningsValg(bool);
	void SpoergEfterOpvaagningsTidspunkt();
	void SetOpvaagningsTid(int, int);
	void SpoergEfterNatTidOensket();
	void SetNatTidValg(bool);
	void SpoergEfterNatTidspunkt();
	void SetNatTid(int, int);
	Mode GetMode();
	void UdskrivModeInfo(string);
	void UdskrivModeAktiveret();
	void SendKommando(int);
	void SpoergEfterStyringsValg();
	void ToggleValgtStyring(int);
};

