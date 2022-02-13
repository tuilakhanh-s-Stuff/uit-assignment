#include <iostream>

void inputArray(int a[], int n)
{
	for (int i = 0; i < n ; i++)
		std::cin >> a[i];
}

int calculateMaxSum(int a[], int n, int b[], int m)
{
	int max = -1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = a[i] + b[j];
			if (max < sum)
			{
				max = sum;
			}
		}
	}
	return max;
}

int main()
{
	int n, m, a[101], b[101];
	std::cin >> n >> m;
	inputArray(a, n);
	inputArray(b, m);
	int max = calculateMaxSum(a, n, b, m);
	std::cout << max;
	return 0;
}
