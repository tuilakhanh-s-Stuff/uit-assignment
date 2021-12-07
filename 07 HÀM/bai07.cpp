/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
int Input() {
  int m;
  cin >> m;
  return m;
}

int sum_even_divisor(int m) {
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    if (m % i == 0 && i % 2 == 0)
        sum = sum + i;
  }
  if (sum == 0)
    return -1;
  else
    return sum;
}

int main() {
	int n;
	n=Input();
	cout << sum_even_divisor(n);
}
