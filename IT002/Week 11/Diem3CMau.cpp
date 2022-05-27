#include "Diem3CMau.h"
#include <iostream>

int Diem3CMau::dem = 0;

Diem3CMau::~Diem3CMau()
{
	std::cout << "Goi ham huy\n";
	dem--;
}

Diem3CMau::Diem3CMau(double x, double y, double z, int r, int g, int b):Diem3C(x, y, z), Mau(r, g, b) {
	dem++;
}

int Diem3CMau::GetDem()
{
	return dem;
}

void Diem3CMau::Nhap() {
	Diem3C::Nhap();
	Mau::Nhap();
}

void Diem3CMau::Xuat() {
	Diem3C::Xuat();
	Mau::Xuat();
}

std::istream& operator>>(std::istream &is, Diem3CMau &dm) {
	dm.Nhap();
	return is;
}

std::ostream& operator<<(std::ostream &os, Diem3CMau dm) {
	dm.Xuat();
	return os;
}
