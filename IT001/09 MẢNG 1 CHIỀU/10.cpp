#include <iostream>

void inputList(int array[], int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

void outputList(int array[], int &n) {
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << ' ';
  }
}

int main() {
  int x, y, a[100], b[100];
  std::cin >> x >> y;
  inputList(a, x);
  inputList(b, y);
  outputList(a, x);
  outputList(b, y);

  return 0;
}
