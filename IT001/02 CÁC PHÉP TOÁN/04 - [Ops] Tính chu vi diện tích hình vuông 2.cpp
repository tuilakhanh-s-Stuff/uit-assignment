#include <iostream>
#include <iomanip>

int main() {

  float Edge;
  std::cin >> Edge;

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Chu vi: " << 4 * Edge << '\n';
  std::cout << "Dien tich: " << Edge * Edge;

}
