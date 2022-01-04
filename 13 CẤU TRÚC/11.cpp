#include <cmath>
#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>

typedef struct Point
{
	int x;
	int y;
} P;

struct TamGiac
{
	Point pA, pB, pC;
	float S, P;
	float gocA, gocB, gocC;
	float a, b, c;
	float R, r;
	float ha, hb, hc;
};

void inputPoint(TamGiac &a)
{
	std::cin >> a.pA.x >> a.pA.y;
	std::cin >> a.pB.x >> a.pB.y;
	std::cin >> a.pC.x >> a.pC.y;
}

float distance(P a, P b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) * 1.0);
}

void calculateTriangle(TamGiac &T)
{
	T.c = distance(T.pA, T.pB);
	T.a = distance(T.pB, T.pC);
	T.b = distance(T.pC, T.pA);
	T.P = (T.a + T.b + T.c) / 2;
	T.S = sqrt(T.P*(T.P - T.a)*(T.P - T.b)*(T.P - T.c));
	T.gocA = acos((pow(T.b, 2) + pow(T.c, 2) - pow(T.a, 2)) / 2*T.b*T.c);
	T.gocB = acos((pow(T.c, 2) + pow(T.a, 2) - pow(T.b, 2)) / 2*T.c*T.a);
	T.gocC = acos((pow(T.a, 2) + pow(T.b, 2) - pow(T.c, 2)) / 2*T.a*T.b);
	T.R = T.a / (2 * std::sin(T.gocA));
	T.r = T.S / T.P;
	T.ha = (2 * T.S) / T.a;
	T.hb = (2 * T.S) / T.b;
	T.hc = (2 * T.S) / T.c;
}

int main()
{
	TamGiac T;
	inputPoint(T);
	calculateTriangle(T);
	std::string input;
	std::cin >> input;
	std::cout << std::fixed << std::setprecision(2);
	if (!(T.a + T.b > T.c && T.a + T.c > T.b && T.b + T.c > T.a))
		std::cout << "Day khong phai la tam giac";
	else if (input == "P")
		std::cout << T.P;
	else if (input == "S")
		std::cout << T.S;
	else if (input == "a")
		std::cout << T.a;
	else if (input == "b")
		std::cout << T.b;
	else if (input == "c")
		std::cout << T.c;
	else if (input == "gocA")
		std::cout << T.gocA;
	else if (input == "gocB")
		std::cout << T.gocB;
	else if (input == "gocC")
		std::cout << T.gocC;
	else if (input == "R")
		std::cout << T.R;
	else if (input == "r")
		std::cout << T.r;
	else if (input == "ha")
		std::cout << T.ha;
	else if (input == "hb")
		std::cout << T.hb;
	else if (input == "hc")
		std::cout << T.hc;
	return 0;
}
