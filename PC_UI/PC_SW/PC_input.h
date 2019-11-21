#pragma once




class PC_input
{


public:
	PC_input();
	~PC_input();

	void SendModeToStyring();
	void VaelgNyMode();
	void SendOpvaegningsValg(bool);
	void SendOpvaegningsTid(int, int);
	void SendNatTidValg(bool);
	void SendNatTid(int, int);



};

