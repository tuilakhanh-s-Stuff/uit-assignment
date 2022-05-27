/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//###INSERT CODE HERE -
struct Date {
	int Day, Month, Year;
};

bool Compare(const Date &d1, const Date &d2) {
	if (d1.Year < d2.Year)
		return true;
	else if (d1.Year == d2.Year && d1.Month < d2.Month)
		return true;
	else if (d1.Year == d2.Year && d1.Month == d2.Month && d1.Day < d2.Day)
		return true;

	return false;
}

void Input(Date *&a, int &n) {
	cin >> n;
	a = new Date[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].Day >> a[i].Month >> a[i].Year;
}

void Output(Date *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].Day << ' ' << a[i].Month << ' ' << a[i].Year << '\n';
	}
}

void shellSort(Date *a, int n) {
  Date temp;
  int j = 0;
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      temp = a[i];
      for (j = i; j >= gap && Compare(temp, a[j - gap]); j -= gap) {
        a[j] = a[j - gap];
      }
      a[j] = temp;
    }
  }
}


int main() {
	Date *a;
	int n;

	Input(a, n);
	shellSort(a, n);
	Output(a, n);

	return 0;
}
