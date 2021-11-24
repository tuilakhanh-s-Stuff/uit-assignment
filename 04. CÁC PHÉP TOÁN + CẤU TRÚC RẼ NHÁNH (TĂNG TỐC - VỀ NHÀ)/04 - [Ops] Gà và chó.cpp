#include <iostream>

int main() {

  unsigned int total, foot, chicken, dog;
  std::cin >> total >> foot;

  int D, Dx, Dy;
  D = 2;
  Dx = total * 4 - foot;
  Dy = foot - 2 * total;
  chicken = Dx / D;
  dog = Dy / D;

  std::cout << chicken << ' ' << dog;

  return 0;
}
