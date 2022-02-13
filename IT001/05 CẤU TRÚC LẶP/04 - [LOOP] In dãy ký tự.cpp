#include <iostream>

int main() {

  int n;
  std::cin >> n;
  char c;
  int i;
  while (true) {
    i = 1;
    std::cin >> c;
    if (c == 'X')
      break;
    while (i <= n) {
      std::cout << c << ' ';
      i++;
    }
    std::cout << '\n';
  }
}
