#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <limits>

typedef struct Point
{
	double x, y;	
} P;

void inputArrayPoint(P a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i].x >> a[i].y;
}

double distance(P a, P b)
{
	double x = pow(a.x - b.x, 2);
	double y = pow(a.y - b.y, 2);
	// std::cout << x << ' ' << y << '\t';
	return sqrt(x + y);
}

void outputMaxSTriangle(P x[], int n)
{
	double a, b, c, P;
	float S, max;
	max = 0;
	int indexi = 0, indexj = 0, indexk = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
	 		{
				a = distance(x[i], x[j]);
				b = distance(x[j], x[k]);
				c = distance(x[i], x[k]);
				if (a + b > c && a + c > b && b + c > a)
				{
					P = (a + b + c) / 2;
					S = sqrt(P*(P - a)*(P - b)*(P - c));
					// S = 0.5 * std::abs((x[j].x - x[i].x)*(x[k].y - x[i].y) - (x[k].x - x[i].x)*(x[j].y - x[i].y));
					bool test = max < S && max != S;
					std::cout << i << j << k << '\t' << a << ' ' << b << ' ' << c << '\t'  << S << ' ' <<  test << '\n';
					// std::cout << a << ' ' << b << ' ' << c << '\n';
					if (max < S)
					{
						max = S;
						indexi = i, indexj = j, indexk = k;					
					}
				}
			}
		}
	}
	std::cout << "[";
	std::cout << "(" << x[indexi].x << ", " << x[indexi].y << "), ";
	std::cout << "(" << x[indexj].x << ", " << x[indexj].y << "), ";
	std::cout << "(" << x[indexk].x << ", " << x[indexk].y << ")";
	std::cout << "]";
}

int main()
{
	P a[100];
	int n;
	inputArrayPoint(a, n);
	outputMaxSTriangle(a, n);
	return 0;
}
