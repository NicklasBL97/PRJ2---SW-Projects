#include "PC_styring.h"

/*
//henter og udskriver tiden fra PC
	auto tid = std::chrono::system_clock::now();
	std::time_t tidnu = std::chrono::system_clock::to_time_t(tid);
	// Omregn tid nu(sek siden 1970) til sekunder p� dagen, ved at tage modulos til antal sek p� en dag.
	int tidnusek = tidnu % 86400;
	// Omregn tid nu til min p� dagen, ved at tage antal sek p� en dag og lave til min, ogs� modulos 60
	int tidnumin = (tidnusek / 60) % 60;
	// Omregn tid nu til timer p� dagen, ved at tage antal sek p� en dag og lave til timer, ogs� modulos 60
	// + 1 for at g� til rigtige tids zone og modulos 24 for at sikre man ikke g�r over 24
	int tidnutimer = (((tidnusek / 3600) % 60)+1) % 24;
*/

int main()
{
	// TEST AF PROGRAM 
	PC_styring bo;
	while (1)
	{
		bo.GetMode();
	}
	return 0;
}