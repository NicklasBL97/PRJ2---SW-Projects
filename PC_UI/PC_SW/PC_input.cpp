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

bool PC_input::VaelgOpvaegningsValg()
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
