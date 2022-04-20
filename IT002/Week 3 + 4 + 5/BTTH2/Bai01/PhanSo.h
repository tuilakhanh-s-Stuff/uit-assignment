#pragma once
class PhanSo
{
private:
	int TuSo;
	int MauSo;
public:
	PhanSo(int = 0, int = 1);
	void Nhap();
	void Xuat();
	PhanSo Cong(PhanSo a);
	PhanSo Tru(PhanSo a);
	PhanSo Nhan(PhanSo a);
	PhanSo Chia(PhanSo a);
};

