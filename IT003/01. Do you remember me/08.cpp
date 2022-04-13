#include <iostream>

using namespace std;

bool isPalindrome(int *a, int n)
{
    int low = 0, high = n - 1, check = false;
    while (low < high) 
    {
        if (a[low] != a[high] && check)
            return false;
        else if (a[low] != a[high])
            check = true;
        low++; high--;
    }
    return true;
}

int main()
{
    int n;
	cin >> n;
	int* a = new int[n];	
	for (int i = 0; i < n; i++)
		cin >> a[i];
    cout << (isPalindrome(a, n) ? "TRUE" : "FALSE");
    return 0;
}