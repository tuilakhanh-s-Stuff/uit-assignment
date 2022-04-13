#include <string>

typedef class HocSinh
{
	private:
		std::string HoTen;
		double DiemToan, DiemVan;
	public:
		HocSinh(std::string = "", double = 0, double = 0);
		void Nhap();
		void Xuat();
		double TinhDTB();
		void XepLoai();
} HS;
