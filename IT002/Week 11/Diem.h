#pragma once
#include <istream>
#include <ostream>

class Diem
{
    protected:
        double x, y;
		static int dem;
    public:
        Diem(double = 0, double = 0);
		~Diem();
		double GetX() const;
		double GetY() const;
		void SetX(double);
		void SetY(double);
		void SetXY(double, double);
		static int GetDem();
        void Nhap();
        void Xuat();
        void DiChuyen(double = 0, double = 0);
        bool KiemTraTrungNhau(Diem) const; 
        double TinhKhoangCach(Diem) const;
        Diem DoiXung();
		friend std::istream& operator>>(std::istream&, Diem&);
		friend std::ostream& operator<<(std::ostream&, Diem);
};
