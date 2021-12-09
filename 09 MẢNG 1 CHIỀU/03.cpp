#include <iostream>

void inputList(int array[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

int countArrayEle(int array[], int n, int x) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] == x) {
      count++;
    }
  }
  return count;
}

int main() {
  int n, a[1000000];
  inputList(a, n);
  int x;
  std::cin >> x;
  std::cout << countArrayEle(a, n, x);
}
