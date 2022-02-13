#include <iostream>
#include <iomanip>

int main() {

  int a, b;
  std::cin >> a >> b;

  std::cout << a << " + " << b << " = " << a + b << "\n";
  std::cout << a << " - " << b << " = " << a - b << "\n";
  std::cout << a << " x " << b << " = " << a * b << "\n";
  std::cout << a << " : " << b << " = " << std::fixed << std::setprecision(2) << float(a) / float(b);

}
