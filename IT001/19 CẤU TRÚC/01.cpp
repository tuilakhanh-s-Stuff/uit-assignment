/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <algorithm>
#define MAXN 3000

struct PhanSo
{
	int TuSo, MauSo;
};

void Nhap(PhanSo a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i].TuSo >> a[i].MauSo;
	}
}

PhanSo reduceFrac(PhanSo fac)
{
	int ucln = std::__gcd(fac.TuSo, fac.MauSo);
	fac.TuSo = fac.TuSo / ucln;
	fac.MauSo = fac.MauSo / ucln;
	return fac;
}

void Xuat(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = reduceFrac(a[i]);
		if (a[i].MauSo == 0)
			std::cout << "Khong thoa yeu cau bai toan";
		else if (a[i].MauSo < 0)
			std::cout << -1 * a[i].TuSo << '/' << -1 * a[i].MauSo;
		else if ((a[i].TuSo % a[i].MauSo) == 0)
			std::cout << a[i].TuSo / a[i].MauSo;
		else
			std::cout << a[i].TuSo << '/' << a[i].MauSo;
		std::cout << '\n';
	}
}

int main() {
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}

