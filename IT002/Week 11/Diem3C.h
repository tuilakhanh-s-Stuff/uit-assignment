#pragma once
#include "Diem.h"

class Diem3C : public Diem {
 protected:
  double z;
  static int dem;
  bool KiemTraTamGiac(double, double, double);
 public:
  Diem3C(double = 0, double = 0, double = 0);
  ~Diem3C();
  double GetZ() const;
  void SetZ(double);
  void SetXYZ(double, double, double);
  static int GetDem();
  void Nhap();
  void Xuat();
  void DiChuyen(double = 0, double = 0, double = 0);
  bool KiemTraTrungNhau(Diem3C);
  double TinhKhoangCach(Diem3C) const;
  Diem3C DoiXung();
  double TinhChuVi(Diem3C, Diem3C);
  double TinhDienTich(Diem3C, Diem3C);
  friend std::istream& operator>>(std::istream&, Diem3C&);
  friend std::ostream& operator<<(std::ostream&, Diem3C);
};
