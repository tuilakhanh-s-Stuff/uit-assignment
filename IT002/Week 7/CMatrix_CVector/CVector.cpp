#include "CVector.h"
#include <iostream>

using namespace std;

CVector::CVector(int n) {
  VT.resize(n);
  Length = n;
  for (int i = 0; i < Length; i++) {
    VT[i] = 0;
  }
}

CVector CVector::operator+(const CVector &vt) {
  if (this->Length != vt.Length) {
    cout << "Khong cung do dai!" << endl;
    return *this;
  }
  CVector temp;
  temp = *this;
  for (int i = 0; i < this->Length; i++)
    temp.VT[i] += vt.VT[i];
  return temp;
}

CVector CVector::operator-(const CVector &vt) {
  if (this->Length != vt.Length) {
    cout << "Khong cung do dai!" << endl;
    return *this;
  }
  CVector temp;
  temp = *this;
  for (int i = 0; i < Length; i++)
    temp.VT[i] -= vt.VT[i];
  return temp;
}

CVector CVector::operator*(const CVector &vt) {
  if (this->Length != vt.Length) {
    cout << "Khong cung do dai!" << endl;
    return *this;
  }
  CVector temp;
  temp = *this;
  for (int i = 0; i < Length; i++)
    temp.VT[i] *= vt.VT[i];
  return temp;
}

CVector CVector::operator*(const int k) {
  CVector temp;
  temp = *this;
  for (int i = 0; i < Length; i++)
    temp.VT[i] *= k;
  return temp;
}

ostream &operator<<(ostream &os, const CVector &vt) {
  os << "( ";
  for (int i = 0; i < vt.Length; i++) {
    if (i != vt.Length - 1)
      os << vt.VT[i] << " , ";
    else {
      os << vt.VT[i];
    }
  }
  os << " )";
  return os;
}

istream &operator>>(istream &is, CVector &vt) {
  cout << "Nhap Do Dai: ";
  is >> vt.Length;
  vt.VT.resize(vt.Length);
  cout << "Nhap Phan Tu: " << endl;
  for (int i = 0; i < vt.Length; i++)
    is >> vt.VT[i];
  return is;
}

double CVector::operator[](int i) { return VT[i]; }

int CVector::GetLength() { return Length; }
