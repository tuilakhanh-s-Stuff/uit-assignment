#include <iostream>
#include <string>

int main() {

  int a, b, c;
  std::string Result; 
  std::cin >> a >> b >> c;

  if (((a > 0) && (b > 0) && (c > 0)) && ((a + b > c) && (b + c > a) && (a + c > b))) {
    if ((a == b) && (a == c) && (b == c))
      Result = "DEU";
    else if ((a == b) || (a == c) || (b ==c))
      Result = "CAN";
    else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
      Result = "VUONG";
    else if ((a*a + b*b < c*c) || (a*a + c*c < b*b) || (b*b + c*c < a*a))
      Result = "TU";
    else
      Result = "NHON";
  } else
    Result = "KHONG";

  std::cout << Result;

  return 0;
}
