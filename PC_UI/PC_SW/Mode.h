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
	Mode();
	~Mode();
	void SetMode_id(int);
	int GetMode_id();
	void SetOpvaagningsOenske(bool);
	bool GetOpvaagningsOenske();
	void SetOpvaagningsTidspunkt_timer(int);
	void SetOpvaagningsTidspunkt_Minutter(int);
	void GetOpvaagningstid(int &, int &);
	void SetNatTidOensket(bool);
	bool GetNatTidOenske();
	void SetNatTid_timer(int);
	void SetNatTid_Minutter(int);
	void GetNatTid(int &, int &);
	void SetLysTaendStatus(bool);
	void SetGardinOppeStatus(bool);
};
