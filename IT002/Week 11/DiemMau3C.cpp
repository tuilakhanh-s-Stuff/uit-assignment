#include <iostream>
#include "DiemMau3C.h"

int DiemMau3C::dem = 0;

DiemMau3C::~DiemMau3C()
{
	dem--;
}

DiemMau3C::DiemMau3C(double x, double y, double z, int r, int g, int b):Diem3C(x, y, z)
{
   SetRGB(r, g, b);
	dem++;
}

int DiemMau3C::GetR() const
{
	return r;
}

int DiemMau3C::GetG() const
{
	return g;
}

int DiemMau3C::GetB() const
{
	return b;
}

void DiemMau3C::SetR(int r)
{
	while (r < 0 || r > 255)
	{
		std::cout << "Nhap lai gia tri R: ";
		std::cin >> r;
	}
	this->r = r;
}

void DiemMau3C::SetG(int g)
{
	while (g < 0 || g > 255)
	{
		std::cout << "Nhap lai gia tri G: ";
		std::cin >> g;
	}
	this->g = g;
}

void DiemMau3C::SetB(int b)
{
	while (b < 0 || b > 255)
	{
		std::cout << "Nhap lai gia tri B: ";
		std::cin >> b;
	}
	this->b = b;
}

void DiemMau3C::SetRGB(int r, int g, int b)
{
	SetR(r);
	SetG(g);
	SetB(b);
}

int DiemMau3C::GetDem()
{
	return dem;
}

void DiemMau3C::Nhap()
{
	Diem3C::Nhap();
	do {
		std::cout << "Nhap 3 thong so mau RGB tu 0 den 255: ";
		std::cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}

void DiemMau3C::Xuat()
{
	Diem3C::Xuat();
	std::cout << "(" << r << "," << g << "," << b << ")\n";
}

bool DiemMau3C::KiemTraTrungNhau(DiemMau3C d) {
	return (Diem3C::KiemTraTrungNhau(d) && r == d.r && g == d.g && b == d.b);
}

std::istream& operator>>(std::istream& is, DiemMau3C& d)
{
	d.Nhap();
	return is;
}

std::ostream& operator<<(std::ostream& os, DiemMau3C& d)
{
	d.Xuat();
	return os;
}
