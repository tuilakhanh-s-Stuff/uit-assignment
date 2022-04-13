#include "Student.h"
#include <iomanip>
#include <iostream>

void Input(Student& a)
{
    std::cout << "Nhap Ho va Ten: ";
    std::cin.ignore();
    std::cin.getline(a.HoTen, 100);
    std::cout << "\nNhap diem Toan: ";
    std::cin >> a.Toan;
    std::cout << "\nNhap diem Van: ";
    std::cin >> a.Van;
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

void Student_Program()
{
    system("cls");
    Student a;
    Input(a);
    Output(a);
    std::cout << '\n';
    system("pause");
}