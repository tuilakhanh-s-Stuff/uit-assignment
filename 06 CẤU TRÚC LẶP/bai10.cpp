#include <iostream>
#include <vector>

void quadrants(int x, int y) {
  if (x > 0 && y > 0)
    std::cout << "I";
  else if (x < 0 && y > 0)
    std::cout << "II";
  else if (x < 0 && y < 0)
    std::cout << "III";
  else if (x > 0 && y < 0)
    std::cout << "IV";
  else if (x == 0 && y > 0)
    std::cout << "T";
  else if (x == 0 && y < 0)
    std::cout << "T";
  else if (y == 0 && x < 0)
    std::cout << "H";
  else if (y == 0 && x > 0)
    std::cout << "H";
  else if (x == 0 && y == 0)
    std::cout << "O";
}

int main() {

  int n;
  long x, y;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> x >> y;
    quadrants(x, y);
    std::cout << '\n';
  }
  
  /* for (int i = 0; i < n; i++) { */
  /*   x = coordx[i], y = coordy[i]; */
  /*   quadrants(x, y); */
  /* } */

  return 0;
}
