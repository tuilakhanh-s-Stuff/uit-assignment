/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/
#include <iostream>
#include <cstring>

//###INSERT CODE HERE -
int bin_search(int x, int *A, int n) {
	
	int l = 0;
	int r = n - 1;
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
	return -1;
}

void insertion_binary_search_sort(int ms, int *a, int &n) {
	int i;
	if (n >= 1000000 - 1)
		return;
	if (bin_search(ms, a, n) != -1)
		return;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] > ms)
		 	right = mid - 1;
		else
		 	left = mid + 1;
	}
	for (i = n - 1; i >= left; i--)
	 	a[i+1] = a[i];
	a[left] = ms;

	n++;

	for (int i = 0; i < n; i++)
	 	std::cout << *(a+i) << ' ';
	std::cout << '\n';
}



int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int *a = new int [1000000];
    int x;
    int n = 0, ms;
    do {
        std::cin >> x;
        if (x == 0) break;
        std::cin >> ms;

        if (x == 1) insertion_binary_search_sort(ms, a, n);
        else if (x == 2) std::cout << bin_search(ms, a, n) + 1 << std::endl;
    } while (x > 0);


    return 0;
}
