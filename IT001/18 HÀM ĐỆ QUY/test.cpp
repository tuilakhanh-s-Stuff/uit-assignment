#include <iostream>

int tohop(int n, int k)
{
	if (n < k)
		return 0;
	if (k == 0 || k == n)
		return 1;
	if (k == 1)
		return n;
	return (tohop(n - 1, k - 1) + tohop(n - 1, k));
}

int main()
{
	std::cout << tohop(20, 5);
}
