#pragma once
#include <iostream>
using namespace std;
class PC_input
{


public:
	PC_input();
	~PC_input();

	
	int VaelgNyMode();
	bool VaelgOpvaagningsValg();
	
	void SendOpvaegningsTid(int&, int&);

	bool VaelgNatTidsValg();

	void SendNatTid(int&, int&);

	bool GodkendInfo();
	
};

