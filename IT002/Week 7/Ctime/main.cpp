#include <iostream>
#include "CTime.h"

using namespace std;

int main() {
  CTime a, b;
  int flag, choose, num;
  do {
	system("clear");
    cout << "---------------------------MENU---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor) cho CTime A va B" << endl;
    cout << "2. Nhap CTime A va B" << endl;
    cout << "3. Xuat CTime A va B" << endl;
    cout << "4. Cong CTime A voi mot so" << endl;
    cout << "5. Cong CTime B voi mot so" << endl;
    cout << "6. Cong CTime A voi B" << endl;
    cout << "7. Cong CTime A them 1 don vi" << endl;
	cout << "8. Cong CTime B them 1 don vi" << endl;
	cout << "9. Tru CTime A voi mot so" << endl;
	cout << "10. Tru CTime B voi mot so" << endl;
	cout << "11. Tru CTime A voi B" << endl;
	cout << "12. Tru CTime A di 1 don vi" << endl;
	cout << "13. Tru CTime B di 1 don vi" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua CTime so a va b lan luot la: \n" << a << '\n' << b;
      break;
    case 2:
	  cout << "Nhap CDate A: ";
	  cin >> a;
	  cout << "Nhap CTime B: ";
	  cin >> b;
      break;
    case 3:
	  cout << "CTime A la: " << a << "\nCTime B la: " << b;
      break;
    case 4:
	  cout << "Nhap so: ";
	  cin >> num;
	  cout << "Ket qua cong CTime A voi mot so: " << a + num;
      break;
    case 5:
	  cout << "Nhap so: ";
	  cin >> num;
	  cout << "Ket qua cong CTime B voi mot so: " << b + num;
      break;
    case 6:
	  cout << "Ket qua cong CTime A va B: " << a + b;
      break;
    case 7:
	  a++;
	  cout << "Ket qua cong CTime A len mot don vi: " << a;
      break;
    case 8:
	  b++;
	  cout << "Ket qua cong CTime B len mot don vi: " << b;
      break;
	case 9:
	  cout << "Nhap so: ";
	  cin >> num;
	  cout << "Ket qua tru CTime A voi mot so: " << a - num;
      break; 
	case 10:
	  cout << "Nhap so: ";
	  cin >> num;
	  cout << "Ket qua tru CTime B voi mot so: " << b - num;
      break;
	case 11:
	  cout << "Ket qua tru CTime A va B: " << a - b;
      break;
 	case 12:
	  a--;
	  cout << "Ket qua tru CTime A di mot don vi: " << a;
      break; 
 	case 13:
	  b--;
	  cout << "Ket qua tru CTime B di mot don vi: " << a;
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
