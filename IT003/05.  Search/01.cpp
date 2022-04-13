#include <iostream>

int findLastPos(int A[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int pos = -1;
	if (A[r] == x)
		return r;
	else
		while (l <= r) {
        	int m = l + (r - l) / 2;
        	
			if (A[m] < x)
            	l = m + 1;
			else if (A[m] > x)
            	r = m - 1;
			else if (A[m] == x)
			{
				pos = m;
				l = m + 1;
			}
    	}
    return pos;
}

void findElement(int A[], int n, int B[], int m)
{
	for (int i = 0; i < m; i++)
		std::cout << findLastPos(A, n, B[i]) << '\n';
}

void Input(int A[], int &n)
{
	for (int i = 0; i < n; i++)
		std::cin >> A[i];
}

void Output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << '\n';
}

int main()
{
	int m, n;
	int *A, *B;
	std::cin >> n;
	A = new int[n];
	Input(A, n);

	std::cin >> m;
	B = new int[m];
	Input(B, m);
	
	findElement(A, n, B, m);
	
	return 0;
}
