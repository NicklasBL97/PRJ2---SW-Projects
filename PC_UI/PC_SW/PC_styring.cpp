#include "PC_styring.h"



PC_styring::PC_styring()
{
}


PC_styring::~PC_styring()
{
}

void PC_styring::GetMode()
{
	display_.PrintModevalg();
	int m = input_.VaelgNyMode();
	SetMode(m);
}

void PC_styring::UdskrivModeInfo()
{
	int id = mode_.GetMode_id();
	bool ov = mode_.GetOpvaagningsOenske();
	int otime, omin;
	mode_.GetOpvaagningstid(otime, omin);
	bool nv = mode_.GetNatTidOenske();
	int ntime, nmin;
	mode_.GetNatTid(ntime, nmin);
	display_.PrintModeInfo(id, ov, otime, omin, nv, ntime, nmin);

}

void PC_styring::UdskrivModeAktiveret()
{
	display_.PrintModeAktiveret();
	while (kbhit() == false)
	{

	}
}

void PC_styring::SetMode(int m)
{
	mode_.SetMode_id(m);
	if (mode_.GetMode_id() == 1)
	{
		
	}
	else if (mode_.GetMode_id() == 2)
	{
		
	}
	else if (mode_.GetMode_id() == 3)
	{
		SpoergEfterOpvaagningOenskes();
		if (mode_.GetOpvaagningsOenske() == true)
		{
			SpoergEfterOpvaagningsTidspunkt();
		}
		SpoergEfterNatTidOensket();
		if (mode_.GetNatTidOenske() == true)
		{
			SpoergEfterNatTidspunkt();
		}
		UdskrivModeInfo();
		if (input_.GodkendInfo() == true)
		{
			while (kbhit() == false)
			{
				//sammenlign og send
			}
		}
	
		
	}
	else if (mode_.GetMode_id() == 4)
	{

	}
}

void PC_styring::SpoergEfterOpvaagningOenskes()
{
	display_.PrintErOpOensket();
	bool ov = input_.VaelgOpvaagningsValg();
	mode_.SetOpvaagningsOenske(ov);
}

void PC_styring::SpoergEfterOpvaagningsTidspunkt()
{
	display_.PrintHvornaarOpTid();
	int time, min;
	input_.SendOpvaegningsTid(time, min);
	SetOpvaagningsTid(time, min);
}

void PC_styring::SetOpvaagningsTid(int time, int min)
{
	mode_.SetOpvaagningsTidspunkt_timer(time);
	mode_.SetOpvaagningsTidspunkt_Minutter(min);
}

void PC_styring::SpoergEfterNatTidOensket()
{
	display_.PrintErNatTidOensket();
	bool nv = input_.VaelgNatTidsValg();
	mode_.SetNatTidOensket(nv);
}

void PC_styring::SpoergEfterNatTidspunkt()
{
	display_.PrintHvornaarNatTid();
	int time, min;
	input_.SendNatTid(time, min);
	SetNatTid(time, min);
}

void PC_styring::SetNatTid(int time, int min)
{
	mode_.SetNatTid_timer(time);
	mode_.SetNatTid_Minutter(min);
}


