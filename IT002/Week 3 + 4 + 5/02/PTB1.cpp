#include "PTB1.h"
#include <iomanip>
#include <iostream>

PTB1::PTB1(double x, double y)
{
	a = x;
	b = y;
}

void PTB1::Nhap()
{
	std::cout << "Nhap 2 he so a ba b: ";
	std::cin >> a >> b;
}

void PTB1::Xuat()
{
	std::cout << "PTB1: " << a << "x";
	if (b >= 0)
		std::cout << " + " << b;
	else
		std::cout << " - " << -b;
	std::cout << " = 0 \n => ";
	Giai();
	std::cout << std::endl;
}

void PTB1::Giai()
{
	if (a == 0)
	{
		if (b == 0)
			std::cout << "Phuong Trinh Vo So Nghiem";
		else
			std::cout << "Phuong Trinh Vo Nghiem";
	}
	else
		std::cout << "Phuong Trinh Co Nghiem x = " << std::setprecision(10) << (-b) / a;
}
