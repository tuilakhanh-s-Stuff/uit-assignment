/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

//###INSERT CODE HERE -
struct Word {
	char *a;
};

int strlen(char a[]) {
	int i;
  	for (i = 0; a[i] != '\0'; i++);
	return i;
}

bool Compare(char a[], char b[]) {
	int na = strlen(a);
	int nb = strlen(b);
	int size = na < nb ? na : nb;
	for (int i = 0; i < size; i++) {
		if (a[i] == b[i])
			continue;
		return a[i] < b[i];
	}
	return na < nb;
}

void Input(char **&s, int &n) {
	cin >> n;
	s = new char*[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new char[1000];
		cin >> s[i];
	}
}

void Output(char **s, int n) {
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}
}

void shellSort(char **s, int n) {
  char *temp;
  int j = 0;
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      temp = s[i];
      for (j = i; j >= gap && Compare(temp, s[j - gap]); j -= gap) {
        s[j] = s[j - gap];
      }
      s[j] = temp;
    }
  }
}

int main() {
	char **a;
	int n;
	
	Input(a, n);
	shellSort(a, n);
	Output(a, n);
}
