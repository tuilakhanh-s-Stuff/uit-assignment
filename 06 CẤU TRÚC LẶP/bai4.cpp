#include <iostream>

int main() {

  int n, a, b;
  std::cin >> n >> a >> b;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if ((i % a) == 0 && (i % b) != 0)
      sum += i; 
  }

  std::cout << sum;

  return 0;
}
