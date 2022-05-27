#pragma once
#include "Diem.h"
#include "Mau.h"

class DiemMau : public Diem, public Mau
{
private:
	static int dem;
public:
    ~DiemMau();	
 	DiemMau(double = 0, double = 0, int = 0, int = 0, int = 0);
    static int GetDem();
	void Nhap();
	void Xuat();
 	friend std::istream& operator>>(std::istream&, DiemMau&);
	friend std::ostream& operator<<(std::ostream&, DiemMau);
};
