#include "PC_styring.h"
#define	portnr 4


PC_styring::PC_styring()
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
	int id = mode_.GetMode_id();
	bool ov = mode_.GetOpvaagningsOenske();
	int otime, omin;
	mode_.GetOpvaagningstid(otime, omin);
	bool nv = mode_.GetNatTidOenske();
	int ntime, nmin;
	mode_.GetNatTid(ntime, nmin);
	display_.PrintModeAktiveret(id, ov, otime, omin, nv, ntime, nmin);
	
}

void PC_styring::SetMode(int m)
{
	mode_.SetMode_id(m);
	if (mode_.GetMode_id() == 1)
	{
		if (Uart_.Open(portnr, 9600) != true)
		{
			display_.ComClosed();
			Sleep(1000);
		}
		else
		{
			display_.PrintHvadSkalStyres();
			int valg = input_.SendStyringsValg();
			if (valg == 1)
			{
				Uart_.sendExample(portnr, 9600, 1); //SEND DATA TÆND LED
				Sleep(1000);
				char data;
				Uart_.ReadData(&data, 1);
				if ( data != 1)
				{
					std::cout << (int)data << endl;
					display_.ComClosed();
				}
				
			}
			else if (valg == 2)
			{
				Uart_.sendExample(portnr, 9600, 2); //SEND DATA TÆND LED
				Sleep(1000);
				char data;
				Uart_.ReadData(&data, 1);
				if (data != 2)
				{
					std::cout << (int)data << endl;
					display_.ComClosed();
				}
			}
			else if (valg == 3)
			{
				Uart_.sendExample(portnr, 9600, 3); //SEND DATA TÆND LED
				Sleep(1000);
				char data;
				Uart_.ReadData(&data, 1);
				if (data != 3)
				{
					std::cout << (int)data << endl;
					display_.ComClosed();
				}
			}
			else if (valg == 4)
			{
				Uart_.sendExample(portnr, 9600, 4); //SEND DATA TÆND LED
				Sleep(1000);
				char data;
				Uart_.ReadData(&data, 1);
				if (data != 4)
				{
					std::cout << (int)data << endl;
					display_.ComClosed();
				}
			}
		}
	}
	else if (mode_.GetMode_id() == 2)
	{
		
	}
	else if (mode_.GetMode_id() == 3)
	{
		if (Uart_.Open(3, 9600) != true)
		{
			display_.ComClosed();
			Sleep(1000);
		}
		else
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
			if (input_.GodkendInfo())
			{
				UdskrivModeAktiveret();
				_sleep(500);
				while (_kbhit() == false)
				{
					_sleep(1000);
					//henter og udskriver tiden fra PC
					auto tid = std::chrono::system_clock::now();
					std::time_t tidnu = std::chrono::system_clock::to_time_t(tid);
					// Omregn tid nu(sek siden 1970) til sekunder på dagen, ved at tage modulos til antal sek på en dag.
					int tidnusek = tidnu % 86400;
					// Omregn tid nu til min på dagen, ved at tage antal sek på en dag og lave til min, også modulos 60
					int tidnumin = (tidnusek / 60) % 60;
					// Omregn tid nu til timer på dagen, ved at tage antal sek på en dag og lave til timer, også modulos 60
					// + 1 for at gå til rigtige tids zone og modulos 24 for at sikre man ikke går over 24
					int tidnutimer = (((tidnusek / 3600) % 60) + 1) % 24;
					//Henter nu mode tider til at sammenligne
					if (mode_.GetOpvaagningsOenske())
					{
						int test_omin, test_otimer;
						mode_.GetOpvaagningstid(test_otimer, test_omin);
						if (test_otimer == tidnutimer && test_omin == tidnumin)
						{
							Uart_.sendExample(portnr, 9600, 1); //SEND DATA TÆND LED
							Sleep(1000);
							char data;
							Uart_.ReadData(&data, 1);
							if (data != 1)
							{
								std::cout << (int)data << endl;
								display_.ComClosed();
							}
							int timer = 0;
							bool loopBool = true;
							while (loopBool == true)
							{
								Sleep(100);
								timer++;
								if (timer >= 590)
								{
									loopBool = false;
								}
								else if (_kbhit())
								{
									loopBool = false;
								}
							}
						}
					}
					if (mode_.GetNatTidOenske())
					{
						int test_nmin, test_ntimer;
						mode_.GetNatTid(test_ntimer, test_nmin);
						if (test_ntimer == tidnutimer && test_nmin == tidnumin)
						{
							Uart_.sendExample(portnr, 9600, 2); //SEND DATA SLUK LED
							Sleep(1000);
							char data;
							Uart_.ReadData(&data, 1);
							if (data != 2)
							{
								std::cout << (int)data << endl;
								display_.ComClosed();
							}
							int timer = 0;
							bool loopBool = true;
							while (loopBool == true)
							{
								Sleep(100);
								timer++;
								if (timer >= 590)
								{
									loopBool = false;
								}
								else if (_kbhit())
								{
									loopBool = false;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (mode_.GetMode_id() == 4)
	{
		if (Uart_.Open(3, 9600) != true)
		{
			display_.ComClosed();
			Sleep(1000);
		}
		else
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
			if (input_.GodkendInfo())
			{
				UdskrivModeAktiveret();
				_sleep(500);
				srand(time(0));
				while (_kbhit() == false)
				{
					_sleep(1000);
					//henter og udskriver tiden fra PC
					auto tid = std::chrono::system_clock::now();
					std::time_t tidnu = std::chrono::system_clock::to_time_t(tid);
					// Omregn tid nu(sek siden 1970) til sekunder på dagen, ved at tage modulos til antal sek på en dag.
					int tidnusek = tidnu % 86400;
					// Omregn tid nu til min på dagen, ved at tage antal sek på en dag og lave til min, også modulos 60
					int tidnumin = (tidnusek / 60) % 60;
					// Omregn tid nu til timer på dagen, ved at tage antal sek på en dag og lave til timer, også modulos 60
					// + 1 for at gå til rigtige tids zone og modulos 24 for at sikre man ikke går over 24
					int tidnutimer = (((tidnusek / 3600) % 60) + 1) % 24;

					//Henter nu mode tider til at sammenligne
					if (mode_.GetOpvaagningsOenske())
					{
						int test_omin, test_otimer;
						mode_.GetOpvaagningstid(test_otimer, test_omin);
						if (test_otimer == tidnutimer && test_omin == tidnumin)
						{
							Uart_.sendExample(portnr, 9600, 1); //SEND DATA TÆND LED
							Sleep(1000);
							char data;
							Uart_.ReadData(&data, 1);
							if (data != 1)
							{
								std::cout << (int)data << endl;
								display_.ComClosed();
							}
							int timer = 0;
							bool loopBool = true;
							while (loopBool == true)
							{
								Sleep(100);
								timer++;
								if (timer >= 590)
								{
									loopBool = false;
								}
								else if (_kbhit())
								{
									loopBool = false;
								}
							}

							//Ændre mode til en ny "random" tid
							test_omin = test_omin + ((rand() - rand()) % 10);
							mode_.SetOpvaagningsTidspunkt_Minutter(test_omin);
							UdskrivModeAktiveret();

						}
					}
					else if (mode_.GetNatTidOenske())
					{
						int test_nmin, test_ntimer;
						mode_.GetNatTid(test_ntimer, test_nmin);
						if (test_ntimer == tidnutimer && test_nmin == tidnumin)
						{
							Uart_.sendExample(portnr, 9600, 2); //SEND DATA SLUK LED
							Sleep(1000);
							char data;
							Uart_.ReadData(&data, 1);
							if (data != 2)
							{
								std::cout << (int)data << endl;
								display_.ComClosed();
							}
							int timer = 0;
							bool loopBool = true;
							while (loopBool == true)
							{
								Sleep(100);
								timer++;
								if (timer >= 590)
								{
									loopBool = false;
								}
								else if (_kbhit())
								{
									loopBool = false;
								}
							}

							//Ændre mode til en ny "random" tid
							test_nmin = test_nmin + ((rand() - rand()) % 10);
							mode_.SetNatTid_Minutter(test_nmin);
							UdskrivModeAktiveret();
						}
					}
				}
			}

		}
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


