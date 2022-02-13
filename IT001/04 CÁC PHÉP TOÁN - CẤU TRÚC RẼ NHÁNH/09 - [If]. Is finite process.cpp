#include <iostream>

int main() {

  int a, b;
  std::cin >> a >> b;

  bool isInfinite;
  int aMod = a % 2;
  int bMod = b % 2;

  if (a < b) {
    if (aMod == 0 && bMod == 0)
      isInfinite = 0;
    else if (aMod != 0 && bMod != 0)
      isInfinite = 0;
    else
      isInfinite = 1;
  } else
      isInfinite = 1;

  std::cout << (isInfinite ? "TRUE" : "FALSE");

  return 0;
}
