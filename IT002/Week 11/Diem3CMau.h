#pragma once
#include "Diem3C.h"
#include "Mau.h"

class Diem3CMau : public Diem3C, public Mau
{
private:
	static int dem;
public:
    ~Diem3CMau();	
 	Diem3CMau(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    static int GetDem();
	void Nhap();
	void Xuat();
 	friend std::istream& operator>>(std::istream&, Diem3CMau&);
	friend std::ostream& operator<<(std::ostream&, Diem3CMau);
};
