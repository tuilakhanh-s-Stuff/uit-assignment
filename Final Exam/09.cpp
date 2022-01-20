#include <iostream>

void inputMatrix(int a[][100], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
			if (a[i][j] == 0)
				a[i][j] = 1;
		}
}

void outputMatrix(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int a[100][100], n;
	inputMatrix(a, n);
	std::cout << "Matrix:\n";
	outputMatrix(a, n);
	return 0;
}
