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
	mode_.SetOpvaagningsTidspunkt_timer(time);
	mode_.SetOpvaagningsTidspunkt_Minutter(min);
}

