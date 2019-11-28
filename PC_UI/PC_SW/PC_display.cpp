#include "PC_display.h"


PC_display::PC_display()
{
}


void PC_display::PrintModevalg()
{
	system("cls");
	cout << "indtast et tal mellem 1-4 for at vaelge et mode:\n\n\n\ntast 1 for Manuel styring\nTast 2 for Vaelg intet program\nTast 3 for opvaegningsprogram\nTast 4 for Tyverisikringsprogram\n";
}

void PC_display::PrintErOpOensket()
{
	system("cls");
	cout << "Er opvaagning Oensket ?\n\nTast 1 for ja\n\nTast 2 for nej\n";
}

void PC_display::PrintHvornaarOpTid()
{
	system("cls");
	cout << "Hvilket tidspunkt skal opvaagning saettes til?\nIndtast foerst time tal og derefter minutter\n";
}

void PC_display::PrintErNatTidOensket()
{
	system("cls");
	cout << "Er nat tid oensket?\n\nTast 1 for ja\n\nTast 2 for nej\n";
}

void PC_display::PrintHvornaarNatTid()
{
	system("cls");
	cout << "Hvilket tidspunkt skal nat tid saettes til?\nIndtast foerst time tal og derefter minutter\n";
}

void PC_display::PrintHvadSkalStyres()
{
	system("cls");
	cout << "Vil du taende for lyset tast 1\n\nVil du slukke for lyset tast 2\n\nVil du rulle gardin op? tast 3\n\nVil du rulle gardin ned? tast 4\n";
}

void PC_display::PrintModeInfo(int id, bool ov, int otime, int omin, bool nv, int ntime, int nmin)
{
	system("cls");

	if (id == 1)
	{
		cout << "Manuel Styring er valgt\n";
	}
	else if (id == 2)
	{
		cout << "Intet program er valgt\n";
	}
	else if (id == 3)
	{
		cout << "Opvaagningsprogram er valgt\n";
		if (ov == true)
		{
			cout << "Opvaagnings tid er indstillet til:" << otime << ":" << omin << endl;
		}
		else
		{
			cout << "Opvaagning ikke valgt" << endl;
		}
		if (nv == true)
		{
			cout << "Nat tid er indstillet til:" << ntime << ":" << nmin << endl;
		}
		else
		{
			cout << "Nat tid ikke valgt" << endl;
		}
		cout << "Vil du godkende valgte indstillinger" << endl << "Tast 1 for ja\nTast 2 for nej\n";
	}
	else if (id == 4)
	{
		cout << "\nTyverisikringsprogram er valgt\n";
	}
}
void PC_display::PrintModeAktiveret(int id, bool ov, int otime, int omin, bool nv, int ntime, int nmin)
{
	system("cls");
	if (id == 1)
	{
		cout << "Manuel Styring er valgt\n";
	}
	else if (id == 2)
	{
		cout << "Intet program er valgt\n";
	}
	else if (id == 3)
	{
		cout << "Opvaagningsprogram er valgt\n";
		if (ov == true)
		{
			cout << "Opvaagnings tid er indstillet til:" << otime << ":" << omin << endl;
		}
		else
		{
			cout << "Opvaagning ikke valgt" << endl;
		}
		if (nv == true)
		{
			cout << "Nat tid er indstillet til:" << ntime << ":" << nmin << endl;
		}
		else
		{
			cout << "Nat tid ikke valgt" << endl;
		}
		
	}
	else if (id == 3)
	{

	}
	cout << "Tryk paa en enter for at vaelge nyt program" << endl;
}
