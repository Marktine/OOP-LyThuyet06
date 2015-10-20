#pragma once
#include <string>
using namespace std;
class CHocSinh
{
private:
	string _name;
	string _adress;
	string _code;
	static int count;
	int _dVan;
	int _dToan;
public:
	CHocSinh();
	static int dem();
	~CHocSinh();
};

