#include "Fraction.h"
#include <iostream>

int main()
{
    PhanSo Frac1, Frac2;
    std::cout << "Nhap phan so thu nhat: ";
    Input(Frac1);
    std::cout << "\nNhap phan so thu hai: ";
    Input(Frac2);
    std::cout << "\nPhan so lon nhat la: ";
    PhanSo max = MAX(Frac1, Frac2);
    Output(max);
    return 0;
}