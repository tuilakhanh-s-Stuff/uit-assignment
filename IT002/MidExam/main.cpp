#include "SoDB.h"
#include <iostream>

void Menu()
{
	std::cout << "Chuong Trinh So Dac Biet.\n";
	std::cout << "1. Thiet lap.\n";
	std::cout << "2. Xuat so N.\n";
	std::cout << "3. Dat so N.\n";
	std::cout << "4. Nhap so N.\n";
	std::cout << "5. Kiem tra N co phai So Nguyen To khong?\n";
	std::cout << "6. Kiem tra N co phai So Chinh Phuong khong?\n";
	std::cout << "7. Kiem tra N co phai So Hoan Thien khong?\n";
	std::cout << "8. Kiem tra N co phai So Doi Xung khong?\n";
	std::cout << "9. Xuat toan bo ham Kiem Tra.\n";
	std::cout << "0. De thoat chuong trinh.\n";
	std::cout << "Vui long chon tinh nang: ";
}

int main()
{
	int choose;
	int nN;
	bool flag = true;
	SoDB *n;
	do {
		system("clear");
		Menu();
		std::cin >> choose;
		switch (choose) {
			case 1:
				n = new SoDB;
				std::cout << "Da thiet lap so N.\n";
				flag = false;
				break;
			case 2:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				std::cout << "So N la: " << n->getN() << '\n';
				break;
			case 3:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				std::cout << "Nhap so de dat cho N: ";
				std::cin >> nN;
				n->setN(nN);
				break;
			case 4:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				n->Nhap();
				break;
			case 5:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				if (n->KiemTraSNT())
					std::cout << n->getN() << " la so nguyen to.\n";
				else
					std::cout << n->getN() << " khong phai la so nguyen to.\n";
				break;
			case 6:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				if (n->KiemTraSCP())
					std::cout << n->getN() << " la so chinh phuong.\n";
				else
					std::cout << n->getN() << " khong phai la so chinh phuong.\n";
				break;
			case 7:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				if (n->KiemTraSHT())
					std::cout << n->getN() << " la so hoan thien.\n";
				else
					std::cout << n->getN() << " khong phai la so hoan thien.\n";
				break;
			case 8:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				if (n->KiemTraSDX())
					std::cout << n->getN() << " la so doi xung.\n";
				else
					std::cout << n->getN() << " khong phai la so doi xung.\n";
				break;
			case 9:
				if (flag)
				{
					std::cout << "Vui long thiet lap N truoc khi thuc hien tinh nang.\n";
					break;
				}
				n->Xuat();
				break;
			case 0:
				std::cout << "Dang thoat chuong trinh...";
				return 0;
			default:
				std::cout << "Lua chon khong hop le vui long nhap lai!\n";
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);

	return 0;
}
