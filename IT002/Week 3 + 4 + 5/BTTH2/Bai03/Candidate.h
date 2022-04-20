#include <string>

class Candidate
{
	private:
		int Ma;
		std::string Ten;
		int ngay, thang, nam;
		float dToan, dVan, dAnh;
	public:
		void Nhap();
		void Xuat();
		float DTB();
		float TongDiem();
};
