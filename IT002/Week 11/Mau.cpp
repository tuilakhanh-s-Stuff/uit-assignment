#include <iostream>
#include <istream>
#include <ostream>
#include "Mau.h"

Mau::Mau(int x, int y, int z): r(x), g(y), b(z) {}

int Mau::GetR() const {
	return b;
}

int Mau::GetG() const {
	return g;
}

int Mau::GetB() const {
	return b;
}

void Mau::SetR(int x) {
	while (x < 0 || x > 255) {
		std::cout << "Nhap thong so mau RED tu 0 den 255: ";
		std::cin >> x;
	}
	this->r = x;
}

void Mau::SetG(int x) {
	while (x < 0 || x > 255) {
		std::cout << "Nhap thong so mau GREEN tu 0 den 255: ";
		std::cin >> x;
	}
	this->g = x;
}

void Mau::SetB(int x) {
	while (x < 0 || x > 255) {
		std::cout << "Nhap thong so mau BLUE tu 0 den 255: ";
		std::cin >> x;
	}
	this->b = x;
}

void Mau::SetRGB(int x, int y, int z) {
	SetR(x);
	SetG(y);
	SetB(z);
}

void Mau::Nhap() {
	do {
		std::cout << "Nhap 3 thong so mau RGB tu 0 den 255";
		std::cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}

void Mau::Xuat() {
	std::cout << "Mau RGB: " << r << " " << g << " " << b << std::endl;
}

bool Mau::KiemTraMauTrungNhau(Mau m) {
 	return (r == m.r && g == m.g && b == m.b);
}

std::istream& operator>>(std::istream& is, Mau& m) {
	m.Nhap();
	return is;
}

std::ostream& operator<<(std::ostream& os, Mau m) {
	m.Xuat();
	return os;
}
