#include "CMatrix.h"
#include "CVector.h"
#include <iostream>

using namespace std;

void CVectorMenu() {
  CVector a, b;
  int flag, choose, num;
  do {
	system("clear");
    cout << "---------------------------CVector---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor) cho CVector A va B" << endl;
    cout << "2. Nhap CVector A va B" << endl;
    cout << "3. Xuat CVector A va B" << endl;
    cout << "4. Cong 2 CVector" << endl;
    cout << "5. Tru 2 CVector" << endl;
    cout << "6. Nhan 2 CVector" << endl;
	cout << "7. Nhan CVector A voi 1 so nguyen" << endl;
	cout << "8. Nhan CVector B voi 1 so nguyen" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua CVector a va b lan luot la: \n" << a << '\n' << b;
      break;
    case 2:
	  cout << "Nhap CVector A: \n";
	  cin >> a;
	  cout << "Nhap CVector B: \n";
	  cin >> b;
      break;
    case 3:
	  cout << "CVector A la: " << a << "\nCVector B la: " << b;
      break;
    case 4:
	  cout << "Ket qua cong 2 CVector: " << a + b;
      break;
    case 5:
	  cout << "Ket qua tru 2 CVector: " << a - b;
      break;
    case 6:
	  cout << "Ket qua nhan 2 CVector: " << a * b;
      break;
    case 7:
	  cout << "Nhap so nguyen: ";
	  cin >> num;
	  cout << "Ket qua nhan CVector A voi 1 so nguyen: " << a * num;
      break;
    case 8:
	  cout << "Nhap so nguyen: ";
	  cin >> num;
	  cout << "Ket qua nhan CVector B voi 1 so nguyen: " << b * num;
      break;
	default:
      cout << "Moi ban chon lai !!! " << endl;
      break;
    }
	cin.ignore();
	cin.get();
  } while (choose != 0);
}

void CMatrixMenu() {
  CMatrix a, b;
  CVector c;
  int flag, choose, num;
  do {
	system("clear");
    cout << "---------------------------CMatrix---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. Thiet lap ( Constructor) cho CMatrix A va B" << endl;
    cout << "2. Nhap CMatrix A va B" << endl;
    cout << "3. Xuat CMatrix A va B" << endl;
    cout << "4. Cong 2 CMatrix" << endl;
    cout << "5. Tru 2 CMatrix" << endl;
    cout << "6. Nhan 2 CMatrix" << endl;
	cout << "7. Nhan CMatrix A voi 1 so nguyen" << endl;
	cout << "8. Nhan CMatrix B voi 1 so nguyen" << endl;
	cout << "9. Nhan CMatrix A voi Vector" << endl;
	cout << "10. Nhan CMatrix B voi Vector" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
      cout << "Thieu lap gia tri mac dinh cua CMatrix a va b lan luot la: \n" << a << '\n' << b;
      break;
    case 2:
	  cout << "Nhap CMatrix A: \n";
	  cin >> a;
	  cout << "Nhap CMatrix B: \n";
	  cin >> b;
      break;
    case 3:
	  cout << "CMatrix A la: " << a << "\nCMatrix B la: " << b;
      break;
    case 4:
	  cout << "Ket qua cong 2 CMatrix: " << a + b;
      break;
    case 5:
	  cout << "Ket qua tru 2 CMatrix: " << a - b;
      break;
    case 6:
	  cout << "Ket qua nhan 2 CMatrix: " << a * b;
      break;
    case 7:
	  cout << "Nhap so nguyen: ";
	  cin >> num;
	  cout << "Ket qua nhan CMatrix A voi 1 so nguyen: " << a * num;
      break;
    case 8:
	  cout << "Nhap so nguyen: ";
	  cin >> num;
	  cout << "Ket qua nhan CMatrix B voi 1 so nguyen: " << b * num;
      break;
	case 9:
	  cout << "Nhap CVector: \n";
	  cin >> c;
	  cout << "CVector: " << c << '\n';
	  cout << "Ket qua nhan CMatrix A voi CVector: " << a * c;
	  break;
	case 10:
	  cout << "Nhap CVector: \n";
	  cin >> c;
	  cout << "CVector: " << c << '\n';
	  cout << "Ket qua nhan CMatrix B voi CVector: " << b * c;
	  break;
	default:
      cout << "Moi ban chon lai !!! " << endl;
      break;
    }
	cin.ignore();
	cin.get();
  } while (choose != 0);
}

int main() {
	int choose;
 	do {
	system("clear");
    cout << "---------------------------MENU---------------------------------- " << endl;
    cout << "0. Thoat CT" << endl;
    cout << "1. CVector" << endl;
    cout << "2. CMatrix" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose) {
    case 0:
      cout << "Dang thoat CT ... \n";
      break;
    case 1:
	  CVectorMenu();
      break;
    case 2:
	  CMatrixMenu();
      break;
	default:
      cout << "Moi ban chon lai !!! " << endl;
      break;
    }
	// cin.ignore();
	// cin.get();
  } while (choose != 0);
  return 0;
}
