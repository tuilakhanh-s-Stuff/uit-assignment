#include <iostream>

int main() {

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++)
    std::cout << "+ ";
  std::cout << '\n';
  for (int i = 0; i < n; i++)
    std::cout << "- ";
  std::cout << '\n';
  for (int i = 0; i <n; i++)
    std::cout << "+ - ";

  return 0;
}
