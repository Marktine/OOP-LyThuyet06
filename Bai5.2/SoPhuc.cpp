#include "SoPhuc.h"

int CSoPhuc::count = 0;

CSoPhuc::CSoPhuc()
{
	_thuc = 0;
	_ao = 0;
	count++;
}

int CSoPhuc::dem()
{
	return count;
}

CSoPhuc::~CSoPhuc()
{
	count--;
}
