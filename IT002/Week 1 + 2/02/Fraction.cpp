#include "Fraction.h"

void Input(PhanSo& Frac)
{
    std::cin >> Frac.TuSo >> Frac.MauSo;
}

void Output(PhanSo Frac)
{
    if (Frac.MauSo == 0)
        std::cout << "Khong thoa yeu cau bai toan";
    else
        std::cout << Frac.TuSo << '/' << Frac.MauSo;
    std::cout << '\n';
}

PhanSo MAX(PhanSo a, PhanSo b){
    double x = static_cast<double>(a.TuSo) / a.MauSo;
	double y = static_cast<double>(b.TuSo) / b.MauSo;
	if (x <= y)
		return b;
    return a;
}