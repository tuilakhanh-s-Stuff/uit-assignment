#include "Fraction.h"
#include "Date.h"
#include "Student.h"
#include "Fraction.h"

int main()
{
    int choose;
    do {
        system("cls");
        std::cout << "\nVui long chon chuong trinh\n";
        std::cout << "1. Tinh toan phan so\n";
        std::cout << "2. Tinh ngay tiep theo\n";
        std::cout << "3. Nhap du lieu hoc sinh\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cin >> choose;
        switch (choose) 
        {
            case 0:
                std::cout << "Dang thoat CT...";
                break;
            case 1:
                Fraction_Program();
                break;
            case 2:
                Date_Program();
                break;
            case 3:
                Student_Program();
                break;
             default:
                std::cout << "Lua chon khong hop le vui long nhap lai!\n";
                system("pause");
                continue;
        }
    } while(choose != 0);   
    return 0;
}