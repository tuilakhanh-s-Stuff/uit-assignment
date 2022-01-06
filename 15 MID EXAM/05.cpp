#include <iostream>

bool isPrime(int n)
{
	if (n < 2)
		return false;
	
	for (int i = 2; i < (n - 1); i++)
		if (n % i == 0)
			return false;
	
	return true;
}

void inputArray(int a[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
}

int check(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (isPrime(a[i]))
			sum += a[i];
	}
	if (sum == 0)
		return -1;
	for (int i = 0; i <= n; i++)
	{
		if (sum % a[i] == 0)
			if (isPrime(a[i]))
				return 1;
	}
	return 0;
}

int main()
{
	int n, a[51];
  inputArray(a, n);
	int i = check(a, n);
	switch(i)
	{
		case -1:
			std::cout << "Khong co so nguyen to";
			break;
		case 0:
			std::cout << "NO";
			break;
		case 1:
			std::cout << "YES";
			break;
	}
	return 0;
}
