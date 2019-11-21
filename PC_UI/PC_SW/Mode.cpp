#include "Mode.h"



Mode::Mode()
{
}


Mode::~Mode()
{
}

void Mode::SetMode_id(int id)
{
	if (4 < id || id < 0)
	{
		cout << "Ugyldig valg, intet program er valgt" << endl;
		mode_id = 4;
	}
	else
	{
		mode_id = id;
	}
}

void Mode::SetOpvaagningsOenske(bool valg)
{
	OpvaagningOenske = valg;
}

void Mode::SetOpvaagningsTidspunkt_timer(int tid)
{
	if (0 < tid < 24)
	{
		OpvaagningsTidspunkt_timer = tid;
	}
	else
	{
		cout << "Ugyldigt time tal indtastet, time tal er sat til 0" << endl;
		OpvaagningsTidspunkt_timer = 0;
	}
}

void Mode::SetOpvaagningsTidspunkt_Minutter(int tid)
{
	if (0 <= tid < 59)
	{
		OpvaagningsTidspunkt_minutter = tid;
	}
	else
	{
		cout << "Ugyldigt min. tal indtastet, time tal er sat til 0" << endl;
		OpvaagningsTidspunkt_minutter = 0;
	}
}

void Mode::SetNatTidOensket(bool valg)
{
	NatTidOensket = valg;
}

void Mode::SetNatTid_timer(int tid)
{
	if (0 < tid < 24)
	{
		NatTid_timer = tid;
	}
	else
	{
		cout << "Ugyldigt time tal indtastet, time tal er sat til 0" << endl;
		NatTid_timer = 0;
	}
}

void Mode::SetNatTid_Minutter(int tid)
{
	if (0 <= tid < 59)
	{
		NatTid_minutter = tid;
	}
	else
	{
		cout << "Ugyldigt min. tal indtastet, time tal er sat til 0" << endl;
		NatTid_minutter = 0;
	}
}
void Mode::SetLysTaendStatus(bool status)
{
	LysTaend = status;
}

void Mode::SetGardinOppeStatus(bool status)
{
	GardinOppe = status;
}
