#include <iostream>
#include "TamGiac.h"

int main()
{
	TamGiac a(10, 11, 12), b, c;
	b.Nhap();
	c.Nhap();

	b.PhanLoai();

	std::cout << "Chu vi Tam Giac C la " << c.TinhChuVi() << '\n';
	std::cout << "Dien tich Tam Giac C la " << c.TinhDienTich() << '\n';

	return 0;
}
