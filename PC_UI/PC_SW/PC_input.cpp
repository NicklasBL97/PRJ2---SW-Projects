#include "PC_input.h"



PC_input::PC_input()
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
	if (x == 1) 
	{
		return true;
	}
	else if (x == 2)
	{
		return false;
	}
	else if (2 > x < 1)
	{
		cout << "Ukendt vaerdi:\nTast 1 for ja eller tast 2 for nej\n";
		return VaelgOpvaagningsValg();
	}
		
}

void PC_input::SendGeneriskTid(int & time, int & min)
{
	while (true)
	{
		if (cin >> time >> min)
		{
			// to tal indtastet - tjek gyldig værdi
			if ((time >= 0) && (time <= 23) && (min >= 0) && (min <= 59))
			{
				return; // alt er godt
			}
		}
		else
		{
			// Ugyldigt input
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Proev igen:\n";
	}
}

void PC_input::SendOpvaegningsTid(int & time, int & min)
{
	SendGeneriskTid(time, min);
}

bool PC_input::VaelgNatTidsValg()
{
	int x;
	cin >> x;
	if (x == 1) 
	{
		return true;
	}
	else if (x == 2)
	{
		return false;
	}
	else if (2 > x < 1)
	{
		cout << "Ukendt vaerdi:\nTast 1 for ja eller tast 2 for nej\n";
		return VaelgNatTidsValg();
	}
}

void PC_input::SendNatTid(int &time, int &min)
{
	SendGeneriskTid(time, min);
}

bool PC_input::GodkendInfo()
{
	int x;
	cin >> x;
	if (x == 1)
	{
		return true;
	}
	else if (x == 2)
	{
		return false;
	}
	else if (2 > x < 1)
	{
		cout << "Ukendt vaerdi:\nTast 1 for at godkende valgte vaerdier eller tast 2 for ikke at godkende valgte vaerdier.\n";
		return GodkendInfo();
	}
}
