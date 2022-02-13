#include <iostream>

int main() {

  int value1, value2, weight1, weight2, maxW;
  std::cin >> value1 >> weight1 >> value2 >> weight2 >> maxW;
  
  int weight = weight1 + weight2;
  int value = 0;
  if (weight <= maxW) {
    value = value1 + value2;
  } else if (weight1 <= maxW && weight2 <= maxW) {
    if (value1 > value2) {
      value = value1;
    }
    else {
      value = value2;
    }
  } else if (weight1 <= maxW && weight2 > maxW) {
    value = value1;
  } else if (weight1 > maxW && weight2 <= maxW) {
    value = value2;
  }

  std::cout << value;

  return 0;
}
