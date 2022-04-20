#include "Hinh_Ve.h"
#include <iostream>

using namespace std;

int main() {
  Hinh_Ve H;
  int flag, choose;
  do {
    cout << "---------------------------MENU---------------------------------- "
         << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor): mac dinh h = 1 " << endl;
    cout << "2. Nhap gia tri h " << endl;
    cout << "3. Ve hinh no dac " << endl;
    cout << "4. Ve hinh no sao rong " << endl;
    cout << "5. Ve hinh tam giac so dac " << endl;
    cout << "6. Ve hinh tam giac so chan le " << endl;
    cout << "7. Xuat " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    cout << endl;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Gia tri mac dinh cua h la : " << H.GetH();
      break;
    case 2:
      H.Nhap();
      break;
    case 3:
      H.Ve_hinh_no_sao_dac();
      cout << endl;
      break;
    case 4:
      H.Ve_hinh_no_sao_rong();
      cout << endl;
      break;
    case 5:
      H.Ve_hinh_tam_giac_so_dac();
      cout << endl;
      break;
    case 6:
      H.Ve_hinh_tam_giac_so_chan_le();
      cout << endl;
      break;
    case 7:
      H.Xuat();
      break;
    default:
      cout << "Moi ban chon lai !!! " << endl;
      break;
    }
	cin.ignore();
	cin.get();
	system("clear");
  } while (choose != 0);
  return 0;
}
