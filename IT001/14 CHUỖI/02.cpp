#include <iostream>
#include <string>
#include <regex>

int main()
{
  std::string s;
  std::getline(std::cin, s);
  s = std::regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
  std::cout << s;
  return 0;
}

