/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     std::ios_base::sync_with_stdio(false)

//###INSERT CODE HERE -
void Input(int *&a, int &n) {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Output(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}

void shellSort(int *a, int n) {
  int temp = 0, j = 0;
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      temp = a[i];
      for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
        a[j] = a[j - gap];
      }
      a[j] = temp;
    }
  }
}

int main() {
	int *a, n;
	srand((unsigned) time(0));
	fast_io;

	Input(a, n);
	shellSort(a, n);
	Output(a, n);

	return 0;
}
