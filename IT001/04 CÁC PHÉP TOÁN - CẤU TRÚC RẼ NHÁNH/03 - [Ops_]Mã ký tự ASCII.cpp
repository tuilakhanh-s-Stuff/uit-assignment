#include <iostream>

int main() {

  char c1, c2, uppper;
  int x, distance;
  std::cin >> c1 >> c2 >> x;

  if (c1 > c2)
    distance = c1 - c2;
  else
    distance = c2 - c1;
  if (std::islower(c1))
    uppper = std::toupper(c1);
  else
    uppper = c1; 

  std::cout << "Ma ASCII cua ky tu `" << c1 << "\', `" << c2 << "\' lan luot la " << (int)c1 << " va " << (int)c2 << '\n';
  std::cout << "Khoang cach giua hai ky tu `" << c1 << "\', `" << c2 << "\' la " << distance << '\n';
  std::cout << "Dang viet hoa cua ky tu `" << c1 << "\' la `" << uppper << "\'\n";
  std::cout << x << " la ma ASCII cua ky tu `" << (char)x << '\'';

  return 0;
}
