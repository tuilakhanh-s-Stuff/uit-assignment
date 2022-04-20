class Diem
{
    private:
        double x, y;    
		bool KiemTraTamGiac(double, double, double);
    public:
        Diem(double = 0, double = 0);
        void Nhap();
        void Xuat();
        void DiChuyen(double = 0, double = 0);
        bool KiemTraTrungNhau(Diem); 
        double TinhKhoangCach(Diem);
        Diem DoiXung();
        double TinhChuVi(Diem, Diem);
        double TinhDienTich(Diem, Diem);
};
