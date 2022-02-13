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
    std::cout << array[i] << '\n';
  }
}

void sort(int array[], int n) {
  int temp, i, j, k;
  for (j = 0; j < n; ++j) {
    for (k = j + 1; k < n; ++k) {
      if (array[j] > array[k]) {
        temp = array[j];
        array[j] = array[k];
        array[k] = temp;
      }
    }
  }
}

int main() {
  int a[10000], n;
  inputList(a, n);
  int evena[10000], odda[10000];
  int evenI = 0, oddI = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] % 2) == 0) {
      evena[evenI++] = a[i];
    } else
      odda[oddI++] = a[i];
  }
  sort(evena, evenI);
  sort(odda, oddI);
  outputList(evena, evenI);
  outputList(odda, oddI);
  
  return 0;
}
