#pragma once
#include <ostream>
#include <istream>

class Mau {
private:
	int r, g, b;
public:
	Mau(int = 0, int = 0, int = 0);
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int, int, int);
	void Nhap();
	void Xuat();
	bool KiemTraMauTrungNhau(Mau);
	friend std::istream& operator>>(std::istream&, Mau&);
	friend std::ostream& operator<<(std::ostream&, Mau);
};
