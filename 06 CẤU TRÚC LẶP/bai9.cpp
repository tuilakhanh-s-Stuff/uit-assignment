#include <iostream>

int main() {

  int n;
  std::cin >> n;

  double pi, sum = 1.0;
  int signs = -1;
  for (int i = 1; i <= n; i++) {
    sum += signs / (2.0 * i + 1.0);
    signs = -signs;
  }
  pi = 4.0 * sum;

  std::cout << pi;

  return 0;
}
