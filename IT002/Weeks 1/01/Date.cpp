#include "Date.h"
#include <iostream>

void Input(Date& a)
{
    std::cout << "Nhap ngay thang nam theo dinh dang DD MM YYYY: ";
    std::cin >> a.Day >> a.Month >> a.Year;
    std::cout << "\n";
}

void Output(Date a)
{
    std::cout << "Ngay tiep theo la: ";
	if (a.Day < 10)
	{
		std::cout << "0" << a.Day << " ";
	}
	else
		std::cout << a.Day << " ";

	if (a.Month < 10)
	{
		std::cout << "0" << a.Month << " ";
	}
	else
		std::cout << a.Month << " ";
	std::cout << a.Year;
}

Date NextDay(Date a)
{
    if (a.Day> 0 && a.Day< 28)
		a.Day+= 1;
	if (a.Day== 28)
	{
		if (a.Month== 2)
		{
			if ((a.Year% 400 == 0) || (a.Year% 100 != 0 || a.Year% 4 == 0))
			{
				a.Day= 29;
			}
			else
			{
				a.Day= 1;
				a.Month= 3;
			}
		}
		else
			a.Day+= 1;
	}
	if (a.Day== 29)
	{
		if (a.Month== 2)
		{
			a.Day= 1;
			a.Month= 3;
		}
		else
			a.Day+= 1;
	}
	if (a.Day== 30)
	{
		if (a.Month== 1 || a.Month== 3 || a.Month== 5 || a.Month== 7 || a.Month== 8 || a.Month== 10 || a.Month== 12)
			a.Day+= 1;
		else
		{
			a.Day= 1;
			a.Month+= 1;
		}
	}
	if (a.Day== 31)
	{
		a.Day= 1;
		if (a.Month== 12)
		{
			a.Year+= 1;
			a.Month= 1;
		}
		else
			a.Month+= 1;
	}
    return a;
}

void Date_Program()
{
	system("cls");
	Date a;
    Input(a);
    Output(NextDay(a));
	std::cout << '\n';
	system("pause");
}