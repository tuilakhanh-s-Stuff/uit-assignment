#include <iostream>


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

void outputArrayFrac(PS a[], int n)
{
	for (int i = n-1; i >= 0; i--)
	{
		std::cout << a[i].TuSo << '/' << a[i].MauSo;
		std::cout << '\n';
	}
}

int main()
{
	PS frac[100000];
	int n;
	inputArrayFrac(frac, n);
	outputArrayFrac(frac, n);
	return 0;
}
