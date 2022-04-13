class SoPhuc
{
private:
	double Thuc, Ao;
public:
	SoPhuc(double = 0, double = 0);
	void Nhap();
	void Xuat();
	SoPhuc Cong(SoPhuc a);
	SoPhuc Tru(SoPhuc a);
	SoPhuc Nhan(SoPhuc a);
	SoPhuc Chia(SoPhuc a);
};
