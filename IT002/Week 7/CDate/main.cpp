#include "CDate.h"
#include <iostream>

using namespace std;

int main() {
 	CDate a, b;
   	int flag, choose, num;
   	do {
	 	system("clear");
     	cout << "---------------------------MENU---------------------------------- " << endl;
     	cout << "0. Thoat CT" << endl;
     	cout << "1. Thiet lap ( Constructor) cho CDate A va B" << endl;
    	cout << "2. Nhap CDate A va B" << endl;
     	cout << "3. Xuat CTDate A va B" << endl;
     	cout << "4. Cong CDate A len 1 so nguyen ngay" << endl;
     	cout << "5. Cong CDate B len 1 so nguyen ngay" << endl;
     	cout << "6. Cong CDate A them 1 ngay" << endl;
	 	cout << "7. Cong CDate B them 1 ngay" << endl;
	 	cout << "8. Khoang cach giua 2 CDate A va B" << endl;
     	cout << "------------------------------------------------------------------" << endl;
     	cout << "Nhap lua chon: ";
    	 cin >> choose;
     	switch (choose) {
     	case 0:
       	cout << "Dang thoat CT ... \n";
       	break;
     	case 1:
       	 	cout << "Thieu lap gia tri mac dinh cua CDate so a va b lan luot la: \n" << a << '\n' << b;
       	 	break;
     	case 2:
	   	 	cout << "Nhap CDate A: \n";
	   	 	cin >> a;
	   	 	cout << "Nhap CDate B: \n";
	   	 	cin >> b;
       	 	break;
     	case 3:
	   	 	cout << "CDate A la: " << a << "\nCDate B la: " << b;
       	 	break;
     	case 4:
	   	 	cout << "Nhap so nguyen ngay: ";
	   	 	cin >> num;
	   	 	cout << "Ket qua cong CDate A voi mot so nguyen ngay: " << a + num;
       	 	break;
     	case 5:
	   	 	cout << "Nhap so nguyen ngay: ";
	   	 	cin >> num;
	   	 	cout << "Ket qua cong CDate B voi mot so: " << b + num;
       	 	break;
     	case 6:
 	 	 	a++;	
			cout << "Ket qua cong CDate A len them 1 ngay: " << a;
       	 	break;
     	case 7:
	   	 	b++;
	   	 	cout << "Ket qua cong CDate B len them 1 ngay: " << b;
       	 	break;
     	case 8:
			cout << "Khoang cach giua 2 CDate A va B: " << a - b;
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
