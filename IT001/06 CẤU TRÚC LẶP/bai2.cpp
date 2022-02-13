#include <iostream>

int main() {

  int n;
  std::cin >> n;
  
  for (int i = 2; i <= n; i++) {
    if ((i % 2) == 0)
      std::cout << i << ' ';
  }
  std::cout << '\n';
  for (int i = n; i >= 1; i--) {
    if ((i % 2) != 0)
      std::cout << i << ' ';
  }
  std::cout << '\n' << "Done";

  return 0;
}
