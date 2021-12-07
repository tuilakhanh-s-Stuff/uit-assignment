#include <iostream>

int main() {

  int min1, min2_10, min11, S;
  std::cin >> min1 >> min2_10 >> min11 >> S;
  int min = 0, factor, charges = 0;

  while (true) {
    min++;

    if (min == 1)
      factor = min1;
    else if (2 <= min && min <= 10)
      factor = min2_10;
    else if (min > 10)
      factor = min11;

    if ((charges + factor) <= S) {
      charges += factor;
    }
    else {
      min--;
      break;
    }
  }

  std::cout << min;

  return 0;
}
