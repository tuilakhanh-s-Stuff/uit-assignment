#include "Diem.h"
#include <iostream>
#include <math.h>

using namespace std;

Diem::Diem(double x, double y)
{
    this->x = x;
    this->y = y;
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

bool Diem::KiemTraTrungNhau(Diem d2)
{
    return (x == d2.x && y == d2.y);
}

double Diem::TinhKhoangCach(Diem d2)
{
   return sqrt(pow(d2.x - x, 2) + pow(d2.y - y, 2) * 1.0); 
}

Diem Diem::DoiXung()
{
    return Diem(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

double Diem::TinhChuVi(Diem d2, Diem d3)
{
    double a = this->TinhKhoangCach(d2); 
    double b = d2.TinhKhoangCach(d3);
    double c = this->TinhKhoangCach(d3);
	if(KiemTraTamGiac(a, b, c))
		return -1;
    return a + b + c;
}

double Diem::TinhDienTich(Diem d2, Diem d3)
{
    double a = this->TinhKhoangCach(d2); 
    double b = d2.TinhKhoangCach(d3);
    double c = this->TinhKhoangCach(d3);
	if(KiemTraTamGiac(a, b, c))
		return -1;
    double P = (a + b + c) / 2;
    return sqrt(P*(P - a)*(P - b)*(P - c));
}

bool Diem::KiemTraTamGiac(double a, double b, double c)
{
	return a<b+c && b<a+c && c<a+b;
}

