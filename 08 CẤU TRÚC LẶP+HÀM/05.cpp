/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -
using namespace std;

int reverse(int n) {
  int reverse = 0;
  while (n > 0) {
    reverse = (reverse * 10) + (n % 10);
    n /= 10;
  }
  return reverse;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
