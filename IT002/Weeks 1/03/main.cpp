#include "Fraction.h"
#include <iostream>

int main()
{
    PhanSo Frac1, Frac2;
    std::cout << "Nhap phan so thu nhat: ";
    Input(Frac1);
    std::cout << "\nNhap phan so thu hai: ";
    Input(Frac2);
    std::cout << "\nCong: ";
    Output(add(Frac1, Frac2));
    std::cout << "\nTru: ";
    Output(subtract(Frac1, Frac2));
    std::cout << "\nNhan: ";
    Output(multiply(Frac1, Frac2));
    std::cout << "\nChia: ";
    Output(divide(Frac1, Frac2));
    return 0;
}