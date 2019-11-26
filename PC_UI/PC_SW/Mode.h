#pragma once
#include <iostream>
using namespace std;
class Mode
{
private:
	int mode_id;
	bool OpvaagningOenske;
	int OpvaagningsTidspunkt_timer;
	int OpvaagningsTidspunkt_minutter;
	bool NatTidOensket;
	int NatTid_timer;
	int NatTid_minutter;
	bool LysTaend;
	bool GardinOppe;
public:
	Mode(int id);
	~Mode();
	void SetMode_id(int);
	void SetOpvaagningsOenske(bool);
	void SetOpvaagningsTidspunkt_timer(int);
	void SetOpvaagningsTidspunkt_Minutter(int);
	void SetNatTidOensket(bool);
	void SetNatTid_timer(int);
	void SetNatTid_Minutter(int);
	void SetLysTaendStatus(bool);
	void SetGardinOppeStatus(bool);
};
