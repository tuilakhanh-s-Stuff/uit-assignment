#include "TestCandidate.h"
#include <iostream>

using namespace std;

void TestCandidate::Nhap()
{
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	listCandidate = new Candidate[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao thi sinh " << i + 1 << endl;
		listCandidate[i].Nhap();
	}
}
void TestCandidate::Xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nThong tin cua thi sinh " << i + 1 << " :" << endl;
		listCandidate[i].Xuat();
		cout << "Diem trung binh: " << listCandidate[i].DTB() << endl;
	}
}
void TestCandidate::Tonghon15()
{
	cout << "\nThong tin cua nhung hoc sinh co tong diem hon 15 la:\n";
	for (int i = 0; i < n; i++)
		if (listCandidate[i].TongDiem() > 15)
			listCandidate[i].Xuat();
}
