#include <iostream>
#include "HocSinh.h"

int main()
{
	HS a, b("Hoang Khanh", 9, 7.5), c("Le Khanh", 9, 8), d;
	d.Nhap();

	a.Xuat();
	a.XepLoai();
	
	b.Xuat();
	b.XepLoai();

	c.Xuat();
	c.XepLoai();

	d.Xuat();
	d.XepLoai();

	return 0;
}
