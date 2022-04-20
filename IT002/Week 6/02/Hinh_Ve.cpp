#include "Hinh_Ve.h"
#include <iostream>

using namespace std;

int Hinh_Ve::GetH() { return h; }
bool Hinh_Ve::KiemTraSoNguyenDuong() { return h > 0 ? true : false; }
Hinh_Ve::Hinh_Ve(int h) {
  if (KiemTraSoNguyenDuong())
	this->h = h;
  else
	cout << "h phai lon hon 0!\n";
}
void Hinh_Ve::Prinf1(int x) {
  for (int i = 1; i <= x; i++)
    cout << "*";
}
void Hinh_Ve::Prinf2(int x) {
  for (int i = 1; i <= x; i++) {
    cout << " ";
  }
}

void Hinh_Ve::Nhap() {
  cout << "Moi ban nhap chieu cao h: ";
  cin >> h;
  while (h <= 0)
  {	
    cout << "Moi ban nhap lai so nguyen duong h ( h > 0 ): ";
	cin >> h;
  }
}
void Hinh_Ve::Ve_hinh_no_sao_dac() {
  int k = h;
  for (int i = 1; i <= h - 1; i++) {
    Prinf1(i);
    Prinf2(2 * k - 3);
    Prinf1(i);
    k--;
    cout << endl;
  }
  Prinf1(2 * h - 1);
  cout << endl;
  k = h;
  int j = 1;
  for (int i = h + 1; i <= 2 * h - 1; i++) {
    Prinf1(k - 1);
    Prinf2(j);
    Prinf1(k - 1);
    k--;
    j += 2;
    cout << endl;
  }
}
void Hinh_Ve::Ve_hinh_no_sao_rong() {
  Prinf1(2 * h - 1);
  cout << endl;
  int k = h;
  for (int i = 1; i <= h - 2; i++) {
    Prinf2(i);
    Prinf1(1);
    Prinf2(2 * k - 1 - 2 * i - 2);
    Prinf1(1);
    Prinf2(i);
    cout << endl;
  }
  Prinf2(h - 1);
  Prinf1(1);
  Prinf2(h - 1);
  cout << endl;
  int j = 1;
  for (int i = h + 1; i <= 2 * h - 2; i++) {
    Prinf2(k - 2);
    Prinf1(1);
    Prinf2(j);
    Prinf1(1);
    Prinf2(k - 2);
    k--;
    j += 2;
    cout << endl;
  }
  Prinf1(2 * h - 1);
}
void Hinh_Ve::Ve_hinh_tam_giac_so_dac() {
  for (int i = 1; i < h; i++)
    for (int j = i; j <= 2 * i - 1; j++)
      cout << j << " \n"[j == 2 * i - 1];
  for (int i = h; i <= 2 * h - 1; i++)
    for (int j = i; j <= 2 * h - 1; j++)
      cout << j << " \n"[j == 2 * h - 1];
}
void Hinh_Ve::Ve_hinh_tam_giac_so_chan_le() {
  int n = h;
  for (int i = 1; i < n; i++) {
    for (int j = 2; j <= i; j++)
      cout << "  ";
    for (int j = i, d = 1; d <= 2 * n + 1 - 2 * i; d++, j += 2)
      cout << j << " \n"[d == 2 * n + 1 - 2 * i];
  }
  for (int i = n; i < 2 * n; i++) {
    for (int j = 2; j <= 2 * n - i; j++)
      cout << "  ";
    for (int j = i, d = 1; d <= (i - n) * 2 + 1; d++, j += 2)
      cout << j << " \n"[d == (i - n) * 2 + 1];
  }
}
void Hinh_Ve::Xuat() {
  Ve_hinh_no_sao_dac();
  cout << endl;
  Ve_hinh_no_sao_rong();
  cout << endl;
  Ve_hinh_tam_giac_so_dac();
  cout << endl;
  Ve_hinh_tam_giac_so_chan_le();
  cout << endl;
}
