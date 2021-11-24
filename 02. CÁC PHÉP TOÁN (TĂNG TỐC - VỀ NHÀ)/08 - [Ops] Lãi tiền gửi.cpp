#include <iostream>
#include <math.h>
#include <iomanip>

int main() {

  double Rate, Month;
  unsigned long long Money, Interest;
  std::cin >> Money >> Month >> Rate;

  Interest = Money * Rate * Month / 12 / 100;
  
  std::cout << std::fixed << std::setprecision(0)  << Money + Interest; 

  return 0;
}
