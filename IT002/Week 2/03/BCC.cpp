#include "BCC.h"
#include <iostream>

BCC::BCC(int x, int y)
{
	if (x > 9)
		x = 9;
	if (y > 9)
		y = 9;
	
	m = x;
	n = y;
}

void BCC::Nhap()
{
	do {
		std::cout << "Nhap m va n: ";
		std::cin >> m >> n;
		if (m >= n)
			std::cout << "m phai nho hon n\n";
	}	while (m >= n);
}

void BCC::XuatBCC()
{
	if (m >= 2 && n == 0)
	{
		std::cout << "Bang cuu chuong " << m << "\n\n";
		for (int i = 1; i <= 10; i++)
	   	{
			std::cout  << m << " x " << i << " = " << i * m << '\n';
		}
		std::cout << '\n';
	}
	else if (m >= 2 && n >= 2)
	{
		for (int i = m; i <= n; i++)
		{
			std::cout << "Bang cuu chuong " << i << "\n\n";
			for (int j = 1; j <= 10; j++)
			{
				std::cout  << i << " x " << j << " = " << i * j << '\n';
			}
			std::cout << "\n";
		}
	}
	else if (m == 0 && n == 0)
	{
		for (int i = 1; i <= 10; i++)
		{
			std::cout << "Bang cuu chuong " << i << "\n\n";
			for (int j = 1; j <= 10; j++)
			{
				std::cout  << i << " x " << j << " = " << i * j << '\n';
			}
			std::cout << "\n";
		}
	}
}
