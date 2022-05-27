#include "CMatrix.h"
#include <iostream>
using namespace std;

CMatrix::CMatrix(int m, int n) {
  Rows = m;
  Columns = n;
  VT.resize(Rows);
  for (int i = 0; i < Rows; i++) {
    VT[i].resize(Columns);
    for (int j = 0; j < Columns; j++) {
      VT[i][j] = 0;
    }
  }
}

CMatrix CMatrix::operator+(const CMatrix &MT) {
  if (Rows != MT.Rows || Columns != MT.Columns) {
    cout << "2 ma tran khong tuong thich!" << endl;
    return *this;
  }
  CMatrix temp;
  temp = *this;
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Columns; j++) {
      temp.VT[i][j] += MT.VT[i][j];
    }
  }
  return temp;
}

CMatrix CMatrix::operator-(const CMatrix &MT) {
  if (Rows != MT.Rows || Columns != MT.Columns) {
    cout << "2 ma tran khong tuong thich!" << endl;
    return *this;
  }
  CMatrix temp;
  temp = *this;
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Columns; j++) {
      temp.VT[i][j] -= MT.VT[i][j];
    }
  }
  return temp;
}

CMatrix CMatrix::operator*(const CMatrix &MT) {
  if (Columns != MT.Rows) {
    cout << "2 ma tran khong tuong thich!" << endl;
    return *this;
  }
  CMatrix temp(Rows, MT.Columns);
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < MT.Columns; j++) {
      for (int k = 0; k < Columns; k++) {
        temp.VT[i][j] += this->VT[i][k] * MT.VT[k][j];
      }
    }
  }
  return temp;
}

CMatrix CMatrix::operator*(const int k) {
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Columns; j++) {
      this->VT[i][j] *= k;
    }
  }
  return *this;
}

CMatrix CMatrix::operator*(CVector &vt) {
  CMatrix VT_To_MT(1, vt.GetLength());
  for (int i = 0; i < VT_To_MT.Columns; i++) {
    VT_To_MT.VT[0][i] = vt[i];
  }
  return *this * VT_To_MT;
}

ostream &operator<<(ostream &os, const CMatrix &MT) {
  for (int i = 0; i < MT.Rows; i++) {
    for (int j = 0; j < MT.Columns; j++) {
      os << MT.VT[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

istream &operator>>(istream &is, CMatrix &MT) {
  cout << "Nhap So Hang va So Cot: ";
  is >> MT.Rows >> MT.Columns;
  MT.VT.resize(MT.Rows);
  for (int i = 0; i < MT.Rows; i++) {
    MT.VT[i].resize(MT.Columns);
    for (int j = 0; j < MT.Columns; j++) {
      is >> MT.VT[i][j];
    }
  }
  return is;
}
