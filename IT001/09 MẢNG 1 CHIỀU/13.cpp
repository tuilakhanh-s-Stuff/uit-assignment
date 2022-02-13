/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -

void inputList(int array[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

bool isSmoth(int array[], int n) {
  int middle;
  int pos = n / 2;
  if (n % 2 != 0) {
    middle = array[pos];
  } else {
    middle = array[pos] + array[pos - 1];
  }
  return (array [0] == middle && array[n-1] == middle);
}

int main() {
  int a[100000], n;
  inputList(a, n);
  std::cout << isSmoth(a, n);
}
