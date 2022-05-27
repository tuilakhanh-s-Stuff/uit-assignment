/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
std
###End banned keyword*/

#include <iostream>
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     std::ios_base::sync_with_stdio(false)

//###INSERT CODE HERE -
void Input(int *&a, int &n) {
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand();
}

void Output(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition (int *a, const int &low, const int &high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
	while(true){
        while(left <= right && a[left] < pivot)
			left++;
 	 	while(right >= left && a[right] > pivot)
			right--;
		if (left >= right)
 	 	 	break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(int *a, const int &low, const int &high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
 
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
	int *a, n;
	srand((unsigned) time(0));
	fast_io;
 	
	n = 8e8;
	Input(a, n);

	auto start = std::chrono::steady_clock::now();
	quickSort(a, 0, n-1);
	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}
