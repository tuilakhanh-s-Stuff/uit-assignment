#include <iostream>
#include <bitset>

int main() {

  short n;
  short k;
  std::cin >> n >> k;

  n = n & (~(1<<(k-1)));
  std::cout << n;

  return 0;
}
