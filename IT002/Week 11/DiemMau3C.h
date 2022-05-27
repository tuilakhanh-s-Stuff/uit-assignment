#pragma once
#include "Diem3C.h"

class DiemMau3C : public Diem3C
{
protected:
	int r, g, b;
    static int dem;
public:
 	~DiemMau3C();
	DiemMau3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int, int, int);
	static int GetDem();
	void Nhap();
	void Xuat();
	bool KiemTraTrungNhau(DiemMau3C);
	friend std::istream& operator >> (std::istream&, DiemMau3C&);
	friend std::ostream& operator << (std::ostream&, const DiemMau3C&);
};
