/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/
#include <iostream>

using namespace std;

void erase_then_reverse(int a[], int &n, int i, int k){
//###INSERT CODE HERE -
    for(int j = i; j < i + k; j++)
    {
        for (int k = i; k < n; k++)
            a[k] = a[k + 1];
        n--;
    }
    int low = 0, high = n - 1, temp;
    while (low < high) 
    {
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int n; cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++) cin >> A[i];

    int i, k; cin >> k >> i;
	erase_then_reverse(A, n, i, k);
	for(int i = 0; i < n; i++) cout << A[i] << endl;
}
