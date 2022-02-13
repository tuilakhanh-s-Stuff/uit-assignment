#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

int main() {

  int Year, Index, divYear, Remainder;
  float shortYear;
  std::vector<std::string> Zidiac {"HOI", "TY\'", "SUU", "DAN", "MEO", "THIN", "TY.", "NGO", "MUI", "THAN", "DAU", "TUAT"};
  std::cin >> Year;

  if (Year > 0) {
    shortYear = Year - 3;
    divYear = floor(shortYear / 60);
    Remainder = shortYear - divYear * 60;
    Index = Remainder % 12;
  } else if (Year < 0) {
    Year = Year * -1;
    shortYear = Year + 2;
    divYear = floor(shortYear / 60);
    Remainder = shortYear - divYear * 60;
    Index = (60 - Remainder) % 12;
  }

  std::cout << Zidiac[Index];

  return 0;
}
