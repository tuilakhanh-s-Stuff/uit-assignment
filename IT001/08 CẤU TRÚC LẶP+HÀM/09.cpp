#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

int main() {

  std::string number;
  std::cin >> number;
  std::string rev = std::string(number.rbegin(), number.rend());
  if (number == rev)
    std::cout << '0';
  else
    std::cout << '1';

  return 0;
}
