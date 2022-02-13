#include <iostream>

int main() {

  int k, yellow = 0, red = 0;
  std::cin >> k;
  int i = 1;
  while (i <= k) {
    if (i % 2 == 0) {
      red = red + i * i;
    } else {
      yellow = yellow + i * i;
    }
    i++;
  }
  std::cout << red - yellow;
}
