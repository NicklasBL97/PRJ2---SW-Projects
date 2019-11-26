#include "PC_input.h"



PC_input::PC_input()
{
}


PC_input::~PC_input()
{
}

int PC_input::VaelgNyMode()
{
	int x;
	cin >> x;
	return x;
	
}

bool PC_input::VaelgOpvaagningsValg()
{
	int x;
	cin >> x;
	if (x == 1) {

		return true;
	}
	else
		return false;
}

void PC_input::SendOpvaegningsTid(int & time, int & min)
{
	cin >> time >> min;


}

bool PC_input::VaelgNatTidsValg()
{
	int x;
	cin >> x;
	if (x == 1) {

		return true;
	}
	else
		return false;
}

void PC_input::SendNatTid(int &time, int &min)
{
	cin >> time >> min;


}
