#include <iostream>
#include <algorithm>

typedef struct PhanSo
{
	int TuSo;
	int MauSo;
} PS;

void inputArrayFrac(PS a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i].TuSo >> a[i].MauSo;
	}
}

PS reduceFrac(PS fac)
{
	int ucln = std::__gcd(fac.TuSo, fac.MauSo);
	fac.TuSo = fac.TuSo / ucln;
	fac.MauSo = fac.MauSo / ucln;
	return fac;
}

void outputArrayFrac(PS a[], int n)
{
	for (int i = n-1; i >= 0; i--)
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

int main()
{
	PS frac[10000];
	int n;
	inputArrayFrac(frac, n);
	outputArrayFrac(frac, n);
	return 0;
}
