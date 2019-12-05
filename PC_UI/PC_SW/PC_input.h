#pragma once
#include <iostream>
using namespace std;
class PC_input
{
private:
	void SendGeneriskTid(int & time, int & min);

public:
	PC_input();	
	int VaelgNyMode();
	bool VaelgOpvaagningsValg();
	void SendOpvaegningsTid(int&, int&);
	bool VaelgNatTidsValg();
	void SendNatTid(int&, int&);
	bool GodkendInfo();	
	int SendStyringsValg();
};

