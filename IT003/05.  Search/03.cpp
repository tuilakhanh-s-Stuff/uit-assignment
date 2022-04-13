#include <cmath>
#include <iostream>

int BinarySarch(int A[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int pos = -1;
	int m;
	while (l <= r) {
        m = l + (r - l) / 2;
        	
		if (A[m] < x)
            l = m + 1;
		else if (A[m] > x)
          	r = m - 1;
		else
			return m;
    }
	if (A[0] > x)
		pos = 0;
	else if (A[n-1] < x)
		pos = n - 1;
	return pos;
}

void findKclosest(int A[], int n, int k, int x)
{
	int pos = BinarySarch(A, n, x);
	// std::cout << pos;

	int left = pos - 1;
	int right = pos;

	for (int i = 0; i < k; i++) {
		if (left < 0 || (right < n && (std::abs(A[left] - x) > std::abs(A[right] - x))))
			right++;
		else
			left--;
	}

	left++;
	// std::cout << left << ' ' << right;
	while (left < right) {
		std::cout << A[left] << ' ';
		left++;
	}
}

void Input(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cin >> A[i];
}

int main()
{
	std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
	int *A, n;

	std::cin >> n;
	A = new int[n];
	Input(A, n);

	int k, x;
	std::cin >> k >> x;
	findKclosest(A, n, k, x);

	return 0;
}
