/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
new
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define fast_io     std::ios_base::sync_with_stdio(false)


//###INSERT CODE HERE -
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int pivot, int a[], int &n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		while (a[left] < pivot) left++;
		while (a[right] > pivot) right--;
		if (left <= right) 
	 	{
		 	swap(a[left], a[right]);
		 	left++;
		 	right--;
		}
	}
	return left - 1;
}

int main()
{
    int n, pivot;
    cin >> n >> pivot;
    int * a = new int [n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int p = partition(pivot, a, n);

    for( int i = 0; i < n; i++){
        cout << a[i] << " " ;
    }
    cout << endl << p;
    return 0;
}
