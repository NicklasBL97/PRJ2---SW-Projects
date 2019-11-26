#pragma once
#include <iostream>
using namespace std;
class PC_input
{


public:
	PC_input();
	~PC_input();

	//void SendModeToStyring();
	int VaelgNyMode();
	bool VaelgOpvaegningsValg();
	
	void SendOpvaegningsTid(int&, int&);
	void SendNatTidValg(bool);
	void SendNatTid(int, int);
	void GodkendInfo(bool);
	void SendValgTilStyring(int);
};

