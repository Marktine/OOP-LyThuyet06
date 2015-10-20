#include "DuongTron.h"
#include "Diem.h"

int CDuongTron::count = 0;

CDuongTron::CDuongTron()
{
	O.ganX(0);
	O.ganY(0);
	count++;
}

int CDuongTron::dem()
{
	return count;
}

CDuongTron::~CDuongTron()
{
}
