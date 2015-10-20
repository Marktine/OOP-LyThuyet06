#include "PhanSo.h"
#include <iostream>
using namespace std;

int CPhanSo::count = 0;

CPhanSo::CPhanSo()
{
	_tu = 0;
	_mau = 1;
	count++;
}

int CPhanSo::Dem()
{
	return count;
}

CPhanSo::~CPhanSo()
{
}
