#include "HocSinh.h"
#include <string>
#include <iostream>
#include <iomanip>

HS::HocSinh(std::string a, double b, double c)
{
	HoTen = a;
	DiemToan = b;
	DiemVan = c;
}

void HS::Nhap()
{
	std::cout << "Nhap Ho va Ten Hoc Sinh: ";
	std::getline(std::cin, HoTen);
	std::cout << "Nhap Diem Toan: ";
	std::cin >> DiemToan;
	std::cout << "Nhap Diem Van: ";
	std::cin >> DiemVan;
}

void HS::Xuat()
{
	std::cout << std::setw(20) << "Ho va Ten" << std::setw(20) <<  "Diem Toan" << std::setw(20) << "Diem Van\n";
	std::cout << std::setw(20) << HoTen << std::setw(20) << DiemToan << std::setw(20) << DiemVan << '\n';
}

double HS::TinhDTB()
{
	return (DiemToan + DiemVan) / 2;
}

void HS::XepLoai()
{
	std::string grade;
	double avg = this->TinhDTB();

  	if (9 <= avg && avg <= 10)
    	grade = "XUAT SAC";
  	else if (8 <= avg && avg < 9)
    	grade = "GIOI";
  	else if (7 <= avg && avg < 8)
    	grade = "KHA";
  	else if (6 <= avg && avg < 7)
    	grade = "TB KHA";
  	else if (5 <= avg && avg < 6)
    	grade = "TB";
  	else if (4 <= avg && avg < 5)
    	grade = "YEU";
  	else
    	grade = "KEM";
	
	std::cout << "Loai: " << grade << '\n';
}
