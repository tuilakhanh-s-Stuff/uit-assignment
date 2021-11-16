#include <iostream>
#include <iomanip>

int main() {

  double X, Y;
  std::cin >> X >> Y;

  X = X * 1000;
  Y = Y * 3600;
  std::cout << std::setprecision(15) << X/Y << std::endl;

  return 0;
}
