#include "SoDB.h"
#include <iostream>
#include <math.h>

int SoDB::getN()
{
	return n;
}

void SoDB::setN(int n)
{
	if (n > 0)
		this->n = n;
	else
		std::cout << "So N phai lon hon 0.\n";
}

void SoDB::Nhap()
{
	int n;
	std::cout << "Vui long nhap so N: ";
	std::cin >> n;
	do {
		if (n <= 0)
		{
			std::cout << "N phai lon hon 0. Vui long nhap lai N: ";
			std::cin >> n;
		}	
		else
		{
			break;
		}
	} while(true);
	this->n = n;
}

bool SoDB::KiemTraSNT()
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return false;
}

bool SoDB::KiemTraSCP()
{
	for (int i = 0; i <= n; i++)
		if (i * i == n)
			return true;
	return false;
}

bool SoDB::KiemTraSHT()
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
			sum = sum + i;
	}
	if(sum == n) 
		return true;
	else 
		return false;
}

bool SoDB::KiemTraSDX()
{
	int sum = 0, i, a, b, c;
	a = n;
	for (i = a; a != 0; a = a / 10) {
	    b = a % 10;
		sum = sum * 10 + b;
	}
	if (i == sum)
		return true;
	else
		return false;
}

void SoDB::Xuat()
{
	if (this->KiemTraSNT())
		std::cout << n << " la so nguyen to.\n";
	else
		std::cout << n << " khong phai la so nguyen to.\n";

	if (this->KiemTraSCP())
		std::cout << n << " la so chinh phuong.\n";
	else
		std::cout << n << " khong phai la so chinh phuong.\n";

	if (this->KiemTraSHT())
		std::cout << n << " la so hoan thien.\n";
	else
		std::cout << n << " khong phai la so hoan thien.\n";

	if (this->KiemTraSDX())
		std::cout << n << " la so doi xung.\n";
	else
		std::cout << n << " khong phai la so doi xung.\n";

}
