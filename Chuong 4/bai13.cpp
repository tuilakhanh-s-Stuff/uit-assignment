#include <iostream>
#include <cmath>
#include <math.h>

int main() {

  int Degree, Quadrant;
  std::cin >> Degree;

  while (Degree <= 0)
    Degree += 360;
  while (Degree > 360)
    Degree -= 360;

  if (Degree % 90 == 0)
    Degree -= 90;
  Quadrant = ceil(4 - (Degree / 90.0));
  std::cout << Quadrant; 

  return 0;
}
