#pragma once

#include "CVector.h"
#include <iostream>
#include <vector>

class CMatrix {
private:
  std::vector<std::vector<double>> VT;
  int Rows;
  int Columns;

public:
  CMatrix(int = 0, int = 0);
  ~CMatrix() { }
  CMatrix operator+(const CMatrix &);
  CMatrix operator-(const CMatrix &);
  CMatrix operator*(const CMatrix &);
  CMatrix operator*(const int);
  CMatrix operator*(CVector &);
  friend std::ostream &operator<<(std::ostream &, const CMatrix &);
  friend std::istream &operator>>(std::istream &, CMatrix &);
};
