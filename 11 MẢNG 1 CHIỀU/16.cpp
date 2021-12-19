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

void outputList(int array[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << ' ';
  }
}

void replaceMiddle(int array[], int nArray[], int &n) {
  int middle;
  int pos = n / 2;
  if (n % 2 == 0) {
    pos = pos - 1;
  }
  for (int i = 0; i < pos; i++) {
    nArray[i] = array[i];
  }
  if (n % 2 == 0) {
    nArray[pos] = array[pos] + array[pos+1];
    n = n - 1;
    for (int i = pos + 1; i < n; i++) {
      nArray[i] = array[i+1];
    }
  } else {
    nArray[pos] = array[pos];
    for (int i = pos + 1; i < n; i++) {
      nArray[i] = array[i];
    }
  }
  
}

int main() {
  int a[100000], n;
  inputList(a, n);
  int na[10000];
  replaceMiddle(a, na, n);
  outputList(na, n);
}
