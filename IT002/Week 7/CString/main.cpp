#include "CString.h"
#include <iostream>

using namespace std;

int main() {
 	CString a, b, c;
   	int flag, choose;
   	do {
	 	system("clear");
     	cout << "---------------------------MENU---------------------------------- " << endl;
     	cout << "0. Thoat CT" << endl;
     	cout << "1. Nhap vao chuoi A va B" << endl;
    	cout << "2. Xuat ra chuoi A va B" << endl;
     	cout << "3. Gan Chuoi A cho Chuoi C" << endl;
     	cout << "4. Gan Chuoi B cho Chuoi C" << endl;
     	cout << "5. Cong 2 Chuoi A va B" << endl;
     	cout << "6. Kiem Tra Chuoi A >= B" << endl;
	 	cout << "7. Kiem Tra Chuoi A <= B" << endl;
	 	cout << "8. Kiem Tra Chuoi A > B" << endl;
 	 	cout << "9. Kiem Tra Chuoi A < B" << endl;
 	 	cout << "10. Kiem Tra Chuoi A == B" << endl;
     	cout << "------------------------------------------------------------------" << endl;
     	cout << "Nhap lua chon: ";
    	 cin >> choose;
     	switch (choose) {
     	case 0:
       	cout << "Dang thoat CT ... \n";
       	break;
     	case 1:
			cout << "Nhap chuoi A: ";
			cin.ignore();
			cin >> a;
			cout << "Nhap chuoi B: ";
 	 	 	cin >> b;
       	 	break;
     	case 2:
 	 	 	cout << "Chuoi A: " << a << "\nChuoi B: " << b << '\n';
       	 	break;
     	case 3:
			c = a;
			cout << "Chuoi C: " << c << '\n';
       	 	break;
     	case 4:
	   	  	c = b;
			cout << "Chuoi C: " << c << '\n';	
       	 	break;
		case 5:
			cout << "Ket qua cong 2 chuoi A va B: " << a + b << '\n';
			break;
     	case 6:
			cout << "Chuoi A " << (a >= b ? "" : "khong") << " >= B\n";
       	 	break;
     	case 7:
 	 	  	cout << "Chuoi A " << (a <= b ? "" : "khong") << " <= B\n";
       	 	break;	
     	case 8:
	   	 	cout << "Chuoi A " << (a > b ? "" : "khong") << " > B\n";
       	 	break;
     	case 9:
		 	cout << "Chuoi A " << (a < b ? "" : "khong") << " < B\n";	
       	 	break;
		case 10:
 	 	 	cout << "Chuoi A " << (a == b ? "" : "khong") << " == B\n";
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
