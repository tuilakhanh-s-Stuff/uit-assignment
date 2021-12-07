#include <iostream>
#include <math.h>

int main() {

  long n, temp;
  std::cin >> n;
  
  bool positive = 1;
  if (n < 0) {
    temp = n * -1;
    positive = 0;
  } else
    temp = n;
  int digits = floor(log10(temp)) + 1;
  if (n == 0)
    digits = 1;
  if (positive)
    std::cout << "So " << n << " co " << digits << " chu so";
  else
    std::cout << "So " << n << " co " << digits << " chu so va 1 dau";
  
  return 0;
}
