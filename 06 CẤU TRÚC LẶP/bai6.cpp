#include <iostream>
#include <string>

int main() {

  int x;
  std::cin >> x;

  std::string s = std::to_string(x);
  for (int i = (s.length() - 1); i >= 0; i--)
    std::cout << s[i] << '\n';

  return 0;
}
