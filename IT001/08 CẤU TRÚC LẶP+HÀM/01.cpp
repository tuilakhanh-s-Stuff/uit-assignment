#include <iostream>
#include <vector>

int main() {

  int n;
  std::cin >> n;
  
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  std::cout << sum << ", ";
  std::vector<int> digits;
  while (sum > 0) {
    digits.insert(digits.begin(), sum % 10);
    sum = sum / 10;
  }
  int num2 = digits[digits.size() - 1];
  int num1;
  if (digits.size() == 1)
    num1 = 0;
  else
    num1 = digits[0];
  std::cout << num1 << ", " << num2;

  return 0;
}
