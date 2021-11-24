#include <iostream>
#include <algorithm>

int main() {

  double a, b, c;
  std::cin >> a >> b >> c;

  if (a > c)
    std::swap(a, c);
  if (a > b)
    std::swap(a, b);
  if (b > c)
    std::swap(b, c);

  std::cout << a << ' ' << b << ' ' << c;

  return 0;
}
