
#include "PhanSo.h"
#include <iostream>

using namespace std;

PhanSo::PhanSo(int a, int b)
{
	TuSo = a;
	MauSo = b;
}

void PhanSo::Nhap()
{
	cout << "Nhap vao tu so: ";
	cin >> TuSo;
	cout << "Nhap vao mau so: ";
	cin >> MauSo;
}
void PhanSo::Xuat()
{
	cout << TuSo << "/" << MauSo << endl;
}
PhanSo PhanSo::Cong(PhanSo a)
{
	PhanSo b;
	b.TuSo = TuSo * a.MauSo + a.TuSo * MauSo;
	b.MauSo = a.MauSo * MauSo;
	return b;
}
PhanSo PhanSo::Tru(PhanSo a)
{
	PhanSo b;
	b.TuSo = TuSo * a.MauSo - a.TuSo * MauSo;
	b.MauSo = TuSo * MauSo;
	return b;
}

PhanSo PhanSo::Nhan(PhanSo a)
{
	PhanSo b;
	b.TuSo = TuSo * a.TuSo ;
	b.MauSo = a.MauSo * MauSo;
	return b;
}

PhanSo PhanSo::Chia(PhanSo a)
{
	PhanSo b;
	b.TuSo = TuSo * a.MauSo;
	b.MauSo = a.TuSo * MauSo;
	return b;
}
