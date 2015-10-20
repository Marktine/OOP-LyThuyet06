#include "DonThuc.h"

int CDonThuc::count = 0;

CDonThuc::CDonThuc()
{
	_heso = 0;
	_somu = 0;
	count++;
}

int CDonThuc::dem()
{
	return count;
}

CDonThuc::~CDonThuc()
{
	count--;
}
