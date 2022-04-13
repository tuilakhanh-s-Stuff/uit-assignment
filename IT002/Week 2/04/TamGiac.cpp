#include "TamGiac.h"
#include <iostream>
#include <math.h>

TG::TamGiac(double x, double y, double z) {
  a = x;
  b = y;
  c = z;
}

bool TG::KiemTra() { return a < b + c && b < a + c && c < a + b; }

void TG::Nhap() {
  do {
    std::cout << "Nhap 3 canh tam giac: ";
    std::cin >> a >> b >> c;
    if (this->KiemTra())
      break;
    else
      std::cout << "Ba canh da nhap khong tao thanh tam giac.\n";
  } while (true);
}

void TG::Xuat() {
  std::cout << "Do dai 3 canh tam giac lan luot la: ";
  std::cout << a << ' ' << b << ' ' << c;
}

void TG::PhanLoai() {
  if (a * a == b * b + c * c || b * b == a * a + c * c ||
      c * c == a * a + b * b)
    std::cout << "Day la tam giac vuong";
  else if (a == b && b == c)
    std::cout << "Day la tam giac deu";
  else if (a == b || a == c || b == c)
    std::cout << "Day la tam giac can";
  else if (a * a > b * b + c * c || b * b > a * a + c * c ||
           c * c > a * a + b * b)
    std::cout << "Day la tam giac tu";
  else
    std::cout << "Day la tam giac nhon";

  std::cout << std::endl;
}

double TG::TinhChuVi() { return a + b + c; }

double TG::TinhDienTich() {
  double P = (a + b + c) / 2;
  return sqrt(P * (P - a) * (P - b) * (P - c));
}
