/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
void inputList(int array[]) {
  for (int i = 0; i < 10; i++) {
    std::cin >> array[i];
  }
}

int getFirstDigit(int n) {
  while (n >= 10) {
    n = n / 10;
  }
  return n;
}

bool isBenford(int array[]) {
  int one = 0, four = 0;
  int digit;
  for (int i = 0; i < 10; i++) {
    digit = getFirstDigit(array[i]);
    if (digit == 1) {
      one++;
    } else if (digit == 4) {
      four++;
    }
  }
  if (one == 3 && four == 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int a[1000000];
  inputList(a);
  std::cout << (isBenford(a) ? "TRUE" : "FALSE");
}
