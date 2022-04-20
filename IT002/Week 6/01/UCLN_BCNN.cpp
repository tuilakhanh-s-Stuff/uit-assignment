#include "UCLN_BCNN.h"
#include <iostream>
#include <algorithm>

using namespace std;

UCLN_BCNN::UCLN_BCNN(int a, int b) {
  this->a = a;
  this->b = b;
}

int UCLN_BCNN::GetA() { return a; }

void UCLN_BCNN::SetA(int a) { this->a = a; }

int UCLN_BCNN::GetB() { return b; }

void UCLN_BCNN::SetB(int b) { this->b = b; }

void UCLN_BCNN::Nhap() {
  cout << "Nhap a: ";
  cin >> a;
  cout << "Nhap b: ";
  cin >> b;
}

int UCLN_BCNN::TimUSCLN() {
  int a1 = abs(a);
  int b1 = abs(b);
  if (a1 == 0 && b1 == 0)
    return 1;
  else if (a1 == 0)
    return b1;
  else if (b1 == 0)
	return a1;
  else {
    while (a1 != b1) {
      if (a1 > b1)
        a1 -= b1;
      else
        b1 -= a1;
    }
    return a1;
  }
}

int UCLN_BCNN::TimBSCNN() {
	int a1 = abs(a);
	int b1 = abs(b);
  return (a1 * b) / __gcd(a1, b1);
}

void UCLN_BCNN::Xuat() {
  cout << "Gia tri hien tai cua a la: " << GetA() << endl;
  cout << "Giatri hien tai cua b la : " << GetB() << endl;
  cout << "USCLN cua 2 so nguyen " << GetA() << " va " << GetB() << " la: " << TimUSCLN() << endl;
  cout << "BSCNN cua 2 so nguyen " << GetA() << " va " << GetB() << " la: " << TimBSCNN() << endl;
}
