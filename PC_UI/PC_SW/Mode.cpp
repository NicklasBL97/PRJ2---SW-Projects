#include "Mode.h"



Mode::Mode()
{
	mode_id = 4;
	OpvaagningOenske = false;
	OpvaagningsTidspunkt_timer = 0;
	OpvaagningsTidspunkt_minutter = 0;
	NatTidOensket = false;
	NatTid_timer = 0;
	NatTid_minutter = 0;
	LysTaend = false;
	GardinOppe = false;
}


void Mode::SetMode_id(int id)
{
	if (4 < id || id < 0)
	{
		mode_id = 4;
	}
	else
	{
		mode_id = id;
	}
}

int Mode::GetMode_id()
{
	return mode_id;
}

void Mode::SetOpvaagningsOenske(bool valg)
{
	OpvaagningOenske = valg;
}

bool Mode::GetOpvaagningsOenske()
{
	return OpvaagningOenske;
}

void Mode::SetOpvaagningsTidspunkt_timer(int tid)
{
	if (0 <= tid && tid < 24)
	{
		OpvaagningsTidspunkt_timer = tid;
	}
	else
	{
		OpvaagningsTidspunkt_timer = 0;
	}
}

void Mode::SetOpvaagningsTidspunkt_Minutter(int tid)
{
	if (0 <= tid && tid < 59)
	{
		OpvaagningsTidspunkt_minutter = tid;
	}
	else
	{
		OpvaagningsTidspunkt_minutter = 0;
	}
}

void Mode::GetOpvaagningstid(int &time, int &min)
{
	time = OpvaagningsTidspunkt_timer;
	min = OpvaagningsTidspunkt_minutter;
}

void Mode::SetNatTidOensket(bool valg)
{
	NatTidOensket = valg;
}

bool Mode::GetNatTidOenske()
{
	return NatTidOensket;
}

void Mode::SetNatTid_timer(int tid)
{
	if (0 <= tid && tid < 24)
	{
		NatTid_timer = tid;
	}
	else
	{
		NatTid_timer = 0;
	}
}

void Mode::SetNatTid_Minutter(int tid)
{
	if (0 <= tid && tid < 59)
	{
		NatTid_minutter = tid;
	}
	else
	{
		NatTid_minutter = 0;
	}
}
void Mode::GetNatTid(int &time, int &min)
{
	time = NatTid_timer;
	min = NatTid_minutter;

}
void Mode::SetLysTaendStatus(bool status)
{
	LysTaend = status;
}

void Mode::SetGardinOppeStatus(bool status)
{
	GardinOppe = status;
}
