#include "BCC.h"
#include <iostream>

int main()
{
	BCC b1(4), b2(3, 8), b3(0, 0), b4;
	b4.Nhap();

	b1.XuatBCC();
	b2.XuatBCC();
	b3.XuatBCC();
	b4.XuatBCC();

	return 0;
}
