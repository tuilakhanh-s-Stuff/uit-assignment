#pragma once

#include<vector>
#include<iostream>

class CVector
{
private:
	std::vector<double> VT;
    int Length;
public:
    CVector(int = 0);
    ~CVector() { }
    int GetLength();
    double operator[](int);
    CVector operator+(const CVector &);
    CVector operator-(const CVector &);
    CVector operator*(const CVector &);
    CVector operator*(const int);
    friend std::ostream & operator<<(std::ostream &,const CVector &);
    friend std::istream & operator>>(std::istream &,CVector &);
};
