#include <iostream>

void inputList(int array[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

void outputList(int array[], int n) {
  for (int i = n-1; i >= 0; i--) {
    std::cout << array[i] << '\n';
  }
}

int main() {
  int n, a[1000000];
  inputList(a, n);
  outputList(a, n);
}
