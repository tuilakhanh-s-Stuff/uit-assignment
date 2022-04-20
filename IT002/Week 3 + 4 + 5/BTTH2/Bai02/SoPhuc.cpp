#include <iostream>
#include "SoPhuc.h"
#include <math.h>

using namespace std;

SoPhuc::SoPhuc(double a, double b)
{
	Thuc = a;
	Ao = b;
}

void SoPhuc::Nhap()
{
	cout << "Nhap vao phan thuc: ";
	cin >> Thuc;
	cout << "Nhap vao phan ao: ";
	cin >> Ao;
}

void SoPhuc::Xuat()
{
	if (Ao >= 0)
		cout << Thuc << " + " << Ao << "i" << endl;
	else
		cout << Thuc << " - " << abs(Ao) << "i" << endl;
}

SoPhuc SoPhuc::Cong(SoPhuc a)
{
	SoPhuc kq;
	kq.Thuc = Thuc + a.Thuc;
	kq.Ao = Ao + a.Ao;
	return kq;
}

SoPhuc SoPhuc::Tru(SoPhuc a)
{
	SoPhuc kq;
	kq.Thuc = Thuc - a.Thuc;
	kq.Ao = Ao - a.Ao;
	return kq;
}

SoPhuc SoPhuc::Nhan(SoPhuc a)
{
	SoPhuc kq;
	kq.Thuc = Thuc*a.Thuc - Ao*a.Ao;
	kq.Ao = Thuc * a.Thuc + Ao * a.Ao;
	return kq;
}

SoPhuc SoPhuc::Chia(SoPhuc a)
{
	SoPhuc kq;
	float mau = pow(Ao, 2) + pow(a.Ao, 2);
	kq.Thuc = (Thuc * a.Thuc + Ao * a.Ao) / mau;
	kq.Ao = (Ao* a.Thuc - Thuc * a.Ao) / mau;
	return kq;
}
