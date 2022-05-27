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

void heapify(int *a, const int &n, const int &i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    if (l < n && a[l] > a[largest])
        largest = l;
 
    if (r < n && a[r] > a[largest])
        largest = r;
 
    if (largest != i) {
        swap(a[i], a[largest]);
 
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
 
    for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
	int *a, n;
	srand((unsigned) time(0));
	fast_io;
 	
	n = 8e8;
	Input(a, n);

	auto start = std::chrono::steady_clock::now();
	heapSort(a, n);
	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}
