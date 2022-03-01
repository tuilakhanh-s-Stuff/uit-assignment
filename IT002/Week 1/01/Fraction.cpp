#include "Fraction.h"
#include <algorithm>

void reduceFrac(PhanSo& Frac)
{
    int ucln = std::__gcd(Frac.TuSo, Frac.MauSo);
	Frac.TuSo = Frac.TuSo / ucln;
	Frac.MauSo = Frac.MauSo / ucln;
}

void Input(PhanSo& Frac)
{
    std::cin >> Frac.TuSo >> Frac.MauSo;
}

void Output(PhanSo Frac)
{
    if (Frac.MauSo == 0)
        std::cout << "Khong thoa yeu cau bai toan";
    else if (Frac.MauSo < 0)
        std::cout << -1 * Frac.TuSo << '/' << -1 * Frac.MauSo;
    else if ((Frac.TuSo % Frac.MauSo) == 0)
        std::cout << Frac.TuSo / Frac.MauSo;
    else
        std::cout << Frac.TuSo << '/' << Frac.MauSo;
    std::cout << '\n';
}