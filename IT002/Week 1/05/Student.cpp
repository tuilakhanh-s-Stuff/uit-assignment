#include "Student.h"
#include <iomanip>
#include <iostream>

void Input(Student& a)
{
    std::cin.getline(a.HoTen, 100);
    std::cin >> a.Toan >> a.Van;
    a.DTB = static_cast<float>(a.Toan + a.Van) / 2;
    std::cout << '\n';
}

void Output(Student a)
{
    std::cout << a.HoTen << '\t';
    std::cout << a.Toan << '\t';
    std::cout << a.Van << '\t';
    std::cout << std::setprecision(3) << a.DTB;   
}