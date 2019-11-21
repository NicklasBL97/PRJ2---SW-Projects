#pragma once
class PC_styring
{

public:
	PC_styring();
	~PC_styring();
	void SetMode(int);
	void SpoergEfterOpvaagningOenskes();
	void SpoergEfterValgAfMode();
	void SetOpvaagningsValg(Bool);
	void SpoergEfterOpvaagningsTidspunkt();
	void SetOpvaagningsTid(int, Int);
	void SpoergEfterNatTidOensket();
	void SetNatTidValg(Bool);
	void SpoergEfterNatTidspunkt();
	void SetNatTid(int, Int);
	Mode GetMode();
	void UdskrivModeInfo(String);
	void UdskrivModeAktiveret();
	void SendKommando(int);
	void SpoergEfterStyringsValg();
	void ToggleValgtStyring(int);
};

