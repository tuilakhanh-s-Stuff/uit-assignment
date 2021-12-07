#include <iostream>

int main() {

  int a, b, n, i;
  long long result = 0;
  std::cin >> a >> b >> n;
  while (i < n) {
    result = result + a * b;
    a++;
    b++;
    i++;
  }
  std::cout << result;

}
