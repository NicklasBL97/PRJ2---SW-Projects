#include "PC_styring.h"



PC_styring::PC_styring(Mode mode, PC_display display, PC_input input)
{
	mode_ = mode;
	display_ = display;
	input_ = input;
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
	if (mode_.GetMode_id == 1)
	{
		
	}
	else if (mode_.GetMode_id == 2)
	{

	}
	else if (mode_.GetMode_id == 3)
	{

	}
	else if (mode_.GetMode_id == 4)
	{

	}
}