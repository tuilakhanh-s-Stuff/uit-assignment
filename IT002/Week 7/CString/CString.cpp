#include "CString.h"
#include <iostream>

std::istream& operator>>(std::istream& is, CString& C) {
    getline(is, C.String);
    return is;
}

std::ostream& operator<<(std::ostream& os, const CString& C) {
    os << C.String;
    return os;
}

CString CString::operator+(const CString &C) {
    CString temp;
    temp.String = this->String;
    temp.String += C.String;
    return temp;
}

void CString::operator=(const CString&C) {
    String = C.String;
}

bool CString::operator<(const CString& C) {
    return (this->String.length() < C.String.length());
}

bool CString::operator<=(const CString& C) {
	return (this->String.length() <= C.String.length());
}

bool CString::operator>(const CString& C) {
    return (this->String.length() > C.String.length());
}

bool CString::operator>=(const CString& C) {
    return (this->String.length() >= C.String.length());
}

bool CString::operator==(const CString& C) {
    return (this->String.length() == C.String.length());
}

bool CString::operator!=(const CString& C) {
    return (this->String != C.String);
}
