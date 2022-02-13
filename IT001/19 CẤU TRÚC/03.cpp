/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <algorithm>

struct PhanSo {
	int TuSo;
	int MauSo;
};

void Nhap(PhanSo &a)
{
	std::cin >> a.TuSo >> a.MauSo;
}

PhanSo Nhap()
{
	PhanSo a;
	std::cin >> a.TuSo >> a.MauSo;
	return a;
}

PhanSo Cong(PhanSo a, PhanSo b)
{
	PhanSo sum;
	sum.TuSo = a.TuSo*b.MauSo + a.MauSo*b.TuSo;
	sum.MauSo = a.MauSo*b.MauSo;
	return sum;
}

PhanSo reduceFrac(PhanSo fac)
{
	int ucln = std::__gcd(fac.TuSo, fac.MauSo);
	fac.TuSo = fac.TuSo / ucln;
	fac.MauSo = fac.MauSo / ucln;
	return fac;
}

void Xuat(PhanSo a)
{
	a = reduceFrac(a);
	if (a.MauSo == 0)
		std::cout << "Khong thoa yeu cau bai toan";
	else if (a.MauSo < 0)
		std::cout << -1 * a.TuSo << '/' << -1 * a.MauSo;
	else if ((a.TuSo % a.MauSo) == 0)
		std::cout << a.TuSo / a.MauSo;
	else
		std::cout << a.TuSo << '/' << a.MauSo;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Cong(a, b));
    return 0;
}
