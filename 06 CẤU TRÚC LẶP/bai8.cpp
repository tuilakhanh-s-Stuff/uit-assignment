#include <iostream>
#include <math.h>
#include <iomanip>

int main() {

  int n;
  std::cin >> n;

  long double pows = 0, mul = 0, temp = 1, temp1 = 0;
  double div = 0;
  for (int i = 1; i <= n; i++) {
    temp = temp * i;
    temp1 = temp1 + i;
    pows += pow(i, i);
    mul += temp;
    div += 1.0 / temp1;
  }
  std::cout << pows << '\n' << mul << '\n' << div;

  return 0;
}
