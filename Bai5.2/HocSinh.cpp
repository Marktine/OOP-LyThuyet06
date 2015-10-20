#include "HocSinh.h"
#include <string>
#include <iostream>
using namespace std;

int CHocSinh::count = 0;

CHocSinh::CHocSinh()
{
	_name = "No name";
	_adress = "No adress";
	_code = "No code.";
	_dVan = 0.0;
	_dToan = 0.0;
	count++;
}

int CHocSinh::dem()
{
	return count;
}

CHocSinh::~CHocSinh()
{
	count--;
}
