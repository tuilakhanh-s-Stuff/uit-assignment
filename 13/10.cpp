#include <iostream>
#include <math.h>

typedef struct Point
{
	int x, y;	
} P;

void inputArrayPoint(P a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i].x >> a[i].y;
}

bool inlineCheck(P a, P b, P c)
{
	int check = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	return check == 0 ? true : false;
}

float distance(P a, P b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) * 1.0);
}

void outputArrayTriangle(P x[], int n)
{
	float a, b, c;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
	 		{
				a = distance(x[i], x[j]);
				b = distance(x[j], x[k]);
				c = distance(x[i], x[k]);
				if (a + b > c && a + c > b && b + c > a)
				{
					// std::cout << i << ' ' << j << ' ' << k;
					std::cout << "[";
					std::cout << "(" << x[i].x << ", " << x[i].y << "), ";
					std::cout << "(" << x[j].x << ", " << x[j].y << "), ";
					std::cout << "(" << x[k].x << ", " << x[k].y << ")";
					std::cout << "]\n";
				}
			}
}

int main()
{
	P a[100];
	int n;
	inputArrayPoint(a, n);
	outputArrayTriangle(a, n);
	return 0;
}
