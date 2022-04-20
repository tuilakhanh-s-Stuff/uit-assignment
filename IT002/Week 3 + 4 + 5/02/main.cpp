#include <iostream>
#include "PTB1.h"

int main()
{
	PTB1 PT1(10, 5);
	PTB1 PT2(10);
	PTB1 PT3(0, 10);
	PTB1 PT4;
	PT4.Nhap();

	PT1.Xuat();
	PT2.Xuat();
	PT3.Xuat();
	PT4.Xuat();

	return 0;
}
