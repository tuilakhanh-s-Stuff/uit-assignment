#include "PhanSo.h"
#include <iostream>

using namespace std;

int main() {
  PhanSo a, b;
  int flag, choose;
  do {
	system("clear");
    cout << "---------------------------MENU---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor) cho Phan So A va B" << endl;
    cout << "2. Nhap Phan So A va B" << endl;
    cout << "3. Xuat Phan So A va B" << endl;
    cout << "4. Cong 2 Phan So" << endl;
    cout << "5. Tru 2 Phan So" << endl;
    cout << "6. Nhan 2 Phan So" << endl;
    cout << "7. Chia 2 Phan So" << endl;
	cout << "8. So sanh == 2 Phan So" << endl;
	cout << "9. So sanh != 2 Phan So" << endl;
	cout << "10. So sanh > 2 Phan So" << endl;
	cout << "11. So sanh >= 2 Phan So" << endl;
	cout << "12. So sanh < 2 Phan So" << endl;
	cout << "13. So sanh <= 2 Phan So" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua phan so a va b lan luot la: \n" << a << b;
      break;
    case 2:
	  cout << "Nhap phan so A: ";
	  cin >> a;
	  cout << "Nhap phan so B: ";
	  cin >> b;
      break;
    case 3:
	  cout << "Phan so A la: " << a << "Phan so B la: " << b;
      break;
    case 4:
	  cout << "Ket qua cong 2 phan so: " << a + b;
      break;
    case 5:
	  cout << "Ket qua tru 2 phan so: " << a - b;
      break;
    case 6:
	  cout << "Ket qua nhan 2 phan so: " << a * b;
      break;
    case 7:
	  cout << "Ket qua chia 2 phan so: " << a / b;
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
