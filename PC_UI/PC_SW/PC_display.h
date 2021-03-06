#pragma once
#include <iostream>
using namespace std;
class PC_display
{
private:
	void PrintTid(const char* pretxt, int t, int m, const char* posttxt="");

public:
	PC_display();
	void PrintModevalg();
	void PrintErOpOensket();
	void PrintHvornaarOpTid();
	void PrintErNatTidOensket();
	void PrintHvornaarNatTid();
	void PrintHvadSkalStyres();
	void PrintModeInfo(int id, bool ov, int otime, int omin, bool nv, int ntime, int nmin);
	void PrintModeAktiveret(int id, bool ov, int otime, int omin, bool nv, int ntime, int nmin);
	void ComClosed();
	void Systemlaast();
};

