/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

struct PhanSo {
	int TuSo;
	int MauSo;
};

void Nhap(PhanSo &a)
{
	std::cin >> a.TuSo >> a.MauSo;
}

PhanSo Nhap()
{
	PhanSo a;
	std::cin >> a.TuSo >> a.MauSo;
	return a;
}

int SoSanh(PhanSo a, PhanSo b)
{
	double x = static_cast<double>(a.TuSo) / a.MauSo;
	double y = static_cast<double>(b.TuSo) / b.MauSo;
	if (x == y)
		return 0;
	else if (x < y)
		return -1;
	else
		return 1;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}
