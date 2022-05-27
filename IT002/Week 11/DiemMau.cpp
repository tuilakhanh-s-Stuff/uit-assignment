#include "DiemMau.h"
#include <iostream>

int DiemMau::dem = 0;

DiemMau::~DiemMau()
{
	std::cout << "Goi ham huy\n";
	dem--;
}

DiemMau::DiemMau(double x, double y, int r, int g, int b):Diem(x, y), Mau(r, g, b) {
	dem++;
}

int DiemMau::GetDem()
{
	return dem;
}

void DiemMau::Nhap() {
	Diem::Nhap();
	Mau::Nhap();
}

void DiemMau::Xuat() {
	Diem::Xuat();
	Mau::Xuat();
}

std::istream& operator>>(std::istream &is, DiemMau &dm) {
	dm.Nhap();
	return is;
}

std::ostream& operator<<(std::ostream &os, DiemMau dm) {
	dm.Xuat();
	return os;
}
