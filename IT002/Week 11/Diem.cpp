#include "Diem.h"
#include <iostream>
#include <math.h>

using namespace std;

int Diem::dem = 0;

Diem::Diem(double x, double y)
{
    this->x = x;
    this->y = y;
	dem++;
}

Diem::~Diem() {
	dem--;
}

double Diem::GetX() const {
	return x;
}

double Diem::GetY() const {
	return y;
}

void Diem::SetX(double x) {
	this->x = x;
}

void Diem::SetY(double y) {
	this->y = y;
}

void Diem::SetXY(double x, double y) {
	this->x = x;
	this->y = y;
}

int Diem::GetDem() {
	return dem;
}

void Diem::Nhap()
{
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

void Diem::Xuat()
{
    cout << "(" << x << ", " << y << ")";
}

void Diem::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool Diem::KiemTraTrungNhau(Diem d2) const
{
    return (x == d2.x && y == d2.y);
}

double Diem::TinhKhoangCach(Diem d2) const
{
   return sqrt(pow(d2.x - x, 2) + pow(d2.y - y, 2) * 1.0); 
}

Diem Diem::DoiXung()
{
    return Diem(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

std::istream& operator>>(std::istream& is, Diem& d) {
 	cout << "Nhap x: ";
	is >> d.x;
	cout << "Nhap y: ";
	is >> d.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, Diem d) {
	os << "(" << d.x << ", " << d.y << ")";
	return os;
}

