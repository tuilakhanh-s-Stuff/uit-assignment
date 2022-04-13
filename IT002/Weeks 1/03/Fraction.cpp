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

PS add(PS fac1, PS fac2)
{
	PS sum;
	sum.TuSo = fac1.TuSo*fac2.MauSo + fac1.MauSo*fac2.TuSo;
	sum.MauSo = fac1.MauSo*fac2.MauSo;
	return sum;
}

PS subtract(PS fac1, PS fac2)
{
	PS sub;
	sub.TuSo = fac1.TuSo*fac2.MauSo - fac1.MauSo*fac2.TuSo;
	sub.MauSo = fac1.MauSo*fac2.MauSo;
	return sub;
}

PS multiply(PS fac1, PS fac2)
{
	PS mul;
	mul.TuSo = fac1.TuSo * fac2.TuSo;
	mul.MauSo = fac1.MauSo * fac2.MauSo;
	return mul;
}

PS divide(PS fac1, PS fac2)
{
	PS div;
	div.TuSo = fac1.TuSo * fac2.MauSo;
	div.MauSo = fac1.MauSo * fac2.TuSo;
	return div;
}