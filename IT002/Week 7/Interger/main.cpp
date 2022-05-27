#include "Interger.h"
#include <iostream>

using namespace std;

int main() {
  Interger a, b;
  int flag, choose;
  do {
	system("clear");
    cout << "---------------------------MENU---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor) cho Interger A va B" << endl;
    cout << "2. Nhap Interger A va B" << endl;
    cout << "3. Xuat Interger A va B" << endl;
    cout << "4. Cong 2 Interger" << endl;
    cout << "5. Tru 2 Interger" << endl;
    cout << "6. Nhan 2 Interger" << endl;
    cout << "7. Chia 2 Interger" << endl;
	cout << "8. So sanh == 2 Interger" << endl;
	cout << "9. So sanh != 2 Interger" << endl;
	cout << "10. So sanh > 2 Interger" << endl;
	cout << "11. So sanh >= 2 Interger" << endl;
	cout << "12. So sanh < 2 Interger" << endl;
	cout << "13. So sanh <= 2 Interger" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua Interger a va b lan luot la: \n" << a << ' ' << b;
      break;
    case 2:
	  cout << "Nhap Interger A: ";
	  cin >> a;
	  cout << "Nhap Interger B: ";
	  cin >> b;
      break;
    case 3:
	  cout << "Interger A la: " << a << "\nInterger B la: " << b;
      break;
    case 4:
	  cout << "Ket qua cong 2 Interger: " << a + b;
      break;
    case 5:
	  cout << "Ket qua tru 2 Interger: " << a - b;
      break;
    case 6:
	  cout << "Ket qua nhan 2 Interger: " << a * b;
      break;
    case 7:
	  cout << "Ket qua chia 2 Interger: " << a / b;
      break;
    case 8:
	  cout << "Ket qua a == b: " << (a == b ? "true" : "false");
	  break;
	case 9:
	  cout << "Ket qua a != b: " << (a != b ? "true" : "false");
	  break;
 	case 10:
	  cout << "Ket qua a > b: " << (a > b ? "true" : "false");
 	  break;
 	case 11:
	  cout << "Ket qua a >= b: " << (a >= b ? "true" : "false");
	  break;
 	case 12:
	  cout << "Ket qua a < b: " << (a < b ? "true" : "false");
	  break;
 	case 13:
	  cout << "Ket qua a <= b: " << (a <= b ? "true" : "false");
 	  break;
    default:
      cout << "Moi ban chon lai !!! " << endl;
      break;
    }
	cin.ignore();
	cin.get();
  } while (choose != 0);
  return 0;
}
