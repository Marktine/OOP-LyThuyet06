#include "TArray.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	CTArray<long> a;
	int n;
	int k;
	a.InputArray();
	a.OutputArray();
	cout << "\n-------------------------------\n";
	//cout << "Nhap vao n: ";
	//cin >> n;
	//cout << "Nhap vao k ";
	//cin >> k;
	a.MoveForward().OutputArray();
	return 0;
}