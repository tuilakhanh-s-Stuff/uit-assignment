#include "UCLN_BCNN.h"
#include <iostream>

using namespace std;

int main() {
  UCLN_BCNN so;
  int flag, choose;
  do {
	system("clear");
    cout << "---------------------------MENU---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor): mac dinh a = b = 0 " << endl;
    cout << "2. GetA va SetA " << endl;
    cout << "3. GetB vs SetB " << endl;
    cout << "4. Nhap: gia tri cua a va b " << endl;
    cout << "5. Tim USCLN cua a va b " << endl;
    cout << "6. Tim BSCNN cua a va b " << endl;
    cout << "7. Xuat ( USCLN va BSCNN cua a va b )" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua a va b lan luot la : " << so.GetA() << " " << so.GetB();
      break;
    case 2:
      cout << "GetA = " << so.GetA() << endl;
      cout << "SetA: ";
      int x;
      cin >> x;
      so.SetA(x);
      break;
    case 3:
      cout << "GetB = " << so.GetB() << endl;
      cout << "SetB: ";
      int y;
      cin >> y;
      so.SetB(y);
      break;
    case 4:
      so.Nhap();
      break;
    case 5:
      cout << "Gia tri hien tai cua a la: " << so.GetA() << endl;
      cout << "Giatri hien tai cua b la : " << so.GetB() << endl;
      cout << "USCLN cua 2 so nguyen " << so.GetA() << " va " << so.GetB()
           << " la: " << so.TimUSCLN() << endl;
      break;
    case 6:
      cout << "Gia tri hien tai cua a la: " << so.GetA() << endl;
      cout << "Giatri hien tai cua b la : " << so.GetB() << endl;
      cout << "BSCNN cua 2 so nguyen " << so.GetA() << " va " << so.GetB()
           << " la: " << so.TimBSCNN() << endl;
      break;
    case 7:
      so.Xuat();
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
