#include "PC_display.h"



PC_display::PC_display()
{
}


PC_display::~PC_display()
{
}

void PC_display::PrintModevalg()
{
	cout << "\n\n\n\n\n\n\n\nindtast et tal mellem 1-4 for at vælge et mode:\n\n\n\ntast 1 for Manuel styring\nTast 2 for Vaelg intet program\Tast 3 for opvaegningsprogram\Tast 4 for Tyverisikringsprogram\n\n";
}

void PC_display::PrintErOpOensket()
{
	cout << "\n\n\n\n\n\n\n\nEr opvaagning Oensket ?\n\nTast 1 for ja\n\nTast 2 for nej\n";
}

void PC_display::PrintHvornaarOpTid()
{
	cout << "\n\n\n\n\n\n\n\nHvilket tidspunkt skal opvaagning saettes til?\nIndtast foerst time tal og derefter minutter\n";
}

void PC_display::PrintErNatTidOensket()
{
	cout << "\n\n\n\n\n\n\n\nEr nat tid oensket?\n";
}

void PC_display::PrintHvornaarNatTid()
{
	cout << "\n\n\n\n\n\n\n\nHvilket tidspunkt skal nat tid saettes til?\nIndtast foerst time tal og derefter minutter\n"
}

void PC_display::PrintHvadSkalStyres()
{
	cout << "\n\n\n\n\n\n\n\nVil du taende for lyset tast 1\n\nVil du slukke for lyset tast 2\n\nVil du rulle gardin op? tast 3\n\nVil du rulle gardin ned? tast 4"
}

void PC_display::PrintModeInfo()
{
	//her skal der lige tænkes, hvordan den skal designes for at printe de rigtige ting ud og sådan
}

void PC_display::PrintModeAktiveret()
{
	//her skal der lige tænkes, hvordan den skal designes for at printe de rigtige ting ud og sådan
}
