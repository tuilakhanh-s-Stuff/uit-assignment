#include <iostream>

void inputArray(int a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
}

void coutMax(int a[], int n)
{
	int pos = 0, max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max <= a[i])
		{
			max = a[i];
			pos = i;
		}
	}
	std::cout << max << '\n' << pos;
}

int main()
{
	int n, a[10001];
	inputArray(a, n);
	coutMax(a, n);
	return 0;
}
