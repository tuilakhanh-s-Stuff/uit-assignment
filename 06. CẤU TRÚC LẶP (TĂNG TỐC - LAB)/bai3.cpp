#include <iostream>

int main() {

  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++)
    std::cout << i << ' ';
  std::cout << '\n';
  for (int i = 10; i <= n; i+=5)
    std::cout << i << ' ';
  std::cout << '\n';
  for (int i = 20; i <= n; i+=10)
    std::cout << i << ' ';

  return 0;
}
