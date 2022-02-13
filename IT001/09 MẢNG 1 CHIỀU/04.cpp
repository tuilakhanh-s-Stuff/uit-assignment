#include <iostream>

void inputList(int array[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

void replaceEle(int array[], int n, int x, int y) {
  for (int i = 0; i < n; i++) {
    if (array[i] == x) {
      array[i] = y;
    }
  }
}

void outputList(int array[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << '\n';
  }
}

int main() {
  int n, a[20];
  inputList(a, n);
  int x, y;
  std::cin >> x >> y;
  replaceEle(a, n, x, y);
  outputList(a, n);

  return 0;
}
