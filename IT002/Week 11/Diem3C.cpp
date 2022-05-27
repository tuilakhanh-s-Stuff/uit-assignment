#include "Diem3C.h"
#include <math.h>
#include <iostream>
#include <istream>

int Diem3C::dem = 0;

Diem3C::~Diem3C() {
	dem--;
}

Diem3C::Diem3C(double x, double y, double z):Diem(x, y), z(z) {
	dem++;
}

double Diem3C::GetZ() const {
	return z;
}

void Diem3C::SetZ(double z) {
	this->z = z;
}

void Diem3C::SetXYZ(double x, double y, double z) {
	SetXY(x, y);
	SetZ(z);
}

int Diem3C::GetDem() {
	return dem;
}

void Diem3C::Nhap() {
	Diem::Nhap();
 	std::cout << "Nhap z: ";
	std::cin >> z;
}

void Diem3C::Xuat() {
	std::cout << "(" << GetX() << ", " << GetY() << ", " << z << ")";
}

bool Diem3C::KiemTraTrungNhau(Diem3C d){
	return Diem::KiemTraTrungNhau(d) && z == d.z;
}

void Diem3C::DiChuyen(double dx, double dy, double dz) {
	Diem::DiChuyen(dx,dy);
	z += dz;
}

double Diem3C::TinhKhoangCach(Diem3C d) const {
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow(z - d.z, 2));
}

Diem3C Diem3C::DoiXung() {
	return Diem3C(x == 0 ? 0 : -x, y == 0 ? 0 : -y, z == 0 ? 0 : -z);
}

double Diem3C::TinhChuVi(Diem3C d2, Diem3C d3)
{
    double a = this->TinhKhoangCach(d2); 
    double b = d2.TinhKhoangCach(d3);
    double c = this->TinhKhoangCach(d3);
	if(!KiemTraTamGiac(a, b, c))
		return -1;
    return a + b + c;
}

double Diem3C::TinhDienTich(Diem3C d2, Diem3C d3)
{
    double a = this->TinhKhoangCach(d2); 
    double b = d2.TinhKhoangCach(d3);
    double c = this->TinhKhoangCach(d3);
	if(!KiemTraTamGiac(a, b, c))
		return -1;
    double P = (a + b + c) / 2;
    return sqrt(P*(P - a)*(P - b)*(P - c));
}

std::istream &operator>>(std::istream &is, Diem3C &d) {
	d.Diem::Nhap();
	std::cout << "Nhap z: ";
	is >> d.z;
	return is;
}

std::ostream& operator<<(std::ostream &os, Diem3C d) {
	d.Xuat();
	return os;
}

bool Diem3C::KiemTraTamGiac(double a, double b, double c)
{
	return a<b+c && b<a+c && c<a+b;
}
