#include "Interger.h"
#include <iostream>

Interger::Interger(int a) {
	number = a;
}

Interger operator+(Interger a, Interger b) {
 	return a.number + a.number;
}

Interger operator-(Interger a, Interger b) {
 	return a.number - a.number;
}

Interger operator*(Interger a, Interger b) {
 	return a.number * a.number;
}

Interger operator/(Interger a, Interger b) {
 	return a.number / a.number;
}

bool operator==(Interger a, Interger b) {
 	return a.number == b.number;
}

bool operator!=(Interger a, Interger b) {
 	return a.number != b.number;
}

bool operator>(Interger a, Interger b) {
 	return a.number > b.number;
}

bool operator<(Interger a, Interger b) {
 	return a.number < b.number;
}

bool operator>=(Interger a, Interger b) {
 	return a.number >= b.number;
}

bool operator<=(Interger a, Interger b) {
 	return a.number <= b.number;
}

std::istream& operator>>(std::istream &is, Interger &i) {
 	is >> i.number;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Interger &i) {
 	os << i.number;
	return os;
}
