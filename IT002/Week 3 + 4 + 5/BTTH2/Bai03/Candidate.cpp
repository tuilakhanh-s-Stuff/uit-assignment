#include <iostream>
#include "Candidate.h"
#include <string>

using namespace std;

void Candidate::Nhap()
{
	cout << "Nhap vao ma thi sinh: ";
	cin >> Ma;
	cin.ignore();
	cout << "Nhap vao ten thi sinh: ";
	getline(cin, Ten);
	cout << "Nhap vao ngay thang nam sinh: ";
	cin >> ngay >> thang >> nam;
	cout << "Nhap vao diem toan: ";
	cin >> dToan;
	cout << "Nhap vao diem van: ";
	cin >> dVan;
	cout << "Nhap vao diem anh: ";
	cin >> dAnh;
}

void Candidate::Xuat()
{
	cout << "\nMa thi sinh: " << Ma << endl;
	cout << "Ten thi sinh: " << Ten << endl;
	cout << "Sinh nhat: " << ngay << "/" << thang << "/" << nam << endl;
	cout << "Diem toan: " << dToan << endl;
	cout << "Diem van: " << dVan << endl;
	cout << "Diem anh: " << dAnh << endl;
}

float Candidate::DTB()
{
	return (dToan + dVan + dAnh) / 3;
}

float Candidate::TongDiem()
{
	return dToan + dVan + dAnh;
}
