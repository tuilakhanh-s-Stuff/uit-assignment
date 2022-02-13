#include <iostream>

bool isLeap(int Year) {
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

int main() {
  
  int Day, Month, Year;
  std::string Result;
  std::cin >>Month>>Year;

  switch (Month) {
    case 1:
    case 3:
    case 5:
    case 7:          
    case 8:
    case 10:       
    case 12:
      Day = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      Day = 30;
      break;
    case 2:
      if (isLeap(Year))
        Day = 29;
      else
        Day = 28;       
      break;
    default:
      Result = "Thang khong hop le.";
      break;  
  }
  
  if (!(1975 < Year && Year < 2019))
    Result += "Nam khong hop le."; 

  if (Result.empty())
    std::cout<<Day;
  else
    std::cout<<Result; 
  
  return 0; 
}
