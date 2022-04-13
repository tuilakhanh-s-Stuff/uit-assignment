#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main()
{
	SoPhuc a, b;
	a.Nhap();
	b.Nhap();
	a.Xuat();
	b.Xuat();
	cout << "Phep cong: ";
	a.Cong(b).Xuat();
	cout << "Phep tru: ";
	a.Tru(b).Xuat();
	cout << "Phep nhan: ";
	a.Nhan(b).Xuat();
	cout << "Phep chia: ";
	a.Chia(b).Xuat();
}
