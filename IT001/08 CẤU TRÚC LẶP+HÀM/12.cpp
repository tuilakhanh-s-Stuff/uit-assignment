#include <iostream>
#include <iomanip>

void multiplicationTable(int n) {
  for (int i = 1; i <= n; i++) {
    std::cout << std::setw(3);
    for (int j = 1; j <= 10; j++) {
      std::cout << std::setw(3) << i * j << ' ';
    }
    std::cout << '\n'; 
  }
}

void printMultiplicationTable() {
  int n;
  std::cout << "Moi ban nhap 1 so: ";
  std::cin >> n;
  std::cout << '\n';
  while (n < 1 || n > 9) {
    std::cout << "Moi ban nhap 1 so tu 1 den 9: ";
    std::cin >> n;
    std::cout << '\n';
  }
  std::cout << "BANG CUU CHUONG: " << n << '\n';
  multiplicationTable(n);
} 

void menu () {
  char menu;
  do {
    std::cout << "MENU\n";
    std::cout << "t) Tao ra bang cuu chuong\n";
    std::cout << "d) Thoat chuong trinh\n";
    std::cout << "Moi ban lua chon: ";
    std::cin >> menu;
    std::cout << '\n';
    if (menu != 't' && menu != 'd') {
      std::cout << "Lua chon khong hop le\n";
      continue;
    } else if (menu == 'd') {
      std::cout << "Ban da chon thoat khoi chuong trinh. Cam on ban da su dung!";
    } else if (menu == 't') {
      printMultiplicationTable();
    }
  } while(menu != 'd');
}

int main() {
  
  menu();
  
  return 0;
}
