#include <iostream>

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

void swap(int array[], int n) {
  int temp;
  temp = array[0];
  array[0] = array[n-1];
  array[n-1] = temp;
}

int main() {
  int n, a[1000000];
  inputList(a, n);
  swap(a, n);
  outputList(a, n);
}
