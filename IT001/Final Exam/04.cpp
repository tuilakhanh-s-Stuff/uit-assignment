#include <iostream>

void inputArray(int a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
}

void printArray(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
}

bool isPrimes(int a)
{
	if (a == 0 || a == 1)
		return false;
	for (int i = 2; i < a; i++)
		if (a % i == 0)
			return false;
	return true;
}

void append(int a[], int &n, int pos)
{
	pos++;
	n++;
	for (int i = n - 1; i >= pos; i--)
		a[i] = a[i - 1];
	a[pos - 1] = -1;
}

void appendAfterPrimes(int a[], int &n)
{
	int newa[1000000], newn = n, index = 0;
	int pos[1000];
	for (int i = 0; i< n; i++)
	{
		newa[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (isPrimes(a[i]))
		{
			// std::cout << i << ' ';
			append(newa, newn, i + index);
			pos[index] = i + index;
			index++;
		}
	}
	printArray(newa, newn);
	std::cout << '\n';
	printArray(pos, index);
}

int main()
{
	int a[1000000], n;
	inputArray(a, n);
	appendAfterPrimes(a, n);
	return 0;
}
