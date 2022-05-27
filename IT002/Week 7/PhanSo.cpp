#include "PhanSo.h"
#include <algorithm>
#include <iostream>

PhanSo::PhanSo(int a, int b) {
	Set(a, b);
}

void PhanSo::Set(int a, int b)
{
	TuSo = a;
	MauSo = b;
}

PhanSo PhanSo::RutGon() {
	int gcd = std::__gcd(TuSo, MauSo);
	return PhanSo(TuSo / gcd, MauSo / gcd);

}

void PhanSo::ChuanHoa() {
 	RutGon();
	if (MauSo < 0) {
		TuSo = -1 * TuSo;
		MauSo = -1 * MauSo;
	}
}

PhanSo operator+(PhanSo a, PhanSo b) {
	return PhanSo((a.TuSo * b.MauSo) + (a.MauSo * b.TuSo), a.MauSo * b.MauSo).RutGon();
}

PhanSo operator-(PhanSo a, PhanSo b) {
	return PhanSo(a.RutGon() + (b.RutGon() * -1)).RutGon();
}

PhanSo operator*(PhanSo a, PhanSo b) {
	return PhanSo(a.TuSo * b.TuSo, a.MauSo * b.MauSo).RutGon();
}

PhanSo operator/(PhanSo a, PhanSo b) {
	return PhanSo(a.TuSo * b.MauSo, a.MauSo * b.TuSo).RutGon();
}

bool operator==(PhanSo a, PhanSo b) {
 	return (a.TuSo * b.MauSo == a.MauSo * b.TuSo);
}

bool operator!=(PhanSo a, PhanSo b) {
	return !(a == b);
}

bool operator>(PhanSo a, PhanSo b) {
	return (a.TuSo * b.MauSo > a.MauSo * b.TuSo);
}

bool operator>=(PhanSo a, PhanSo b) {
	return (a > b || a == b);
}

bool operator<(PhanSo a, PhanSo b) {
 	return (a.TuSo * b.MauSo < a.MauSo * b.TuSo);
}

bool operator<=(PhanSo a, PhanSo b) {
	return (a < b || a == b);
}

std::ostream& operator<<(std::ostream &os, PhanSo a) {
	a.ChuanHoa();
	if (a.MauSo == 1)
	 	os << a.TuSo << '\n';
	else
	 	os << a.TuSo << '/' << a.MauSo << '\n';
	return os;
}

std::istream& operator>>(std::istream &is, PhanSo &a){
	do {
	 	is >> a.TuSo >> a.MauSo;
		if (a.MauSo == 0)
	 	 	std::cout << "Mau so phai khac 0, vui long nhap lai: ";
	} while (a.MauSo == 0);
	return is;
}
