#include <iostream>
#include "Diem.h"

int ChonDiem()
{
	int slot;
	std::cout << "Chon 1 trong 3 diem: ";
	std::cin >> slot;
	return slot;
}

int main()
{
	Diem *d  = new Diem[3];
	int choose;
	int slot, slot1;
	double CV, DT;
	double x, y;
	do {	
		system("clear");
		std::cout << "----------Chuong trinh tinh toan Diem----------\n";
		// std::cout << "1. Khoi Tao Diem";
		std::cout << "1. Nhap Diem\n";
		std::cout << "2. Xuat Diem\n";
		std::cout << "3. Di Chuyen Diem\n";
		std::cout << "4. Kiem Tra 2 Diem Co Toa Do Trung Nhau\n";
		std::cout << "5. Tinh Khoang Cach Giua 2 Diem\n";
		std::cout << "6. Diem Doi Xung Qua Goc Toa Do\n";
		std::cout << "7. Chu Vi Tam Giac Qua 3 Diem\n";
		std::cout << "8. Dien Tich Tam Giac Qua 3 Diem\n";
		std::cout << "0. Thoat Chuong Trinh\n";
		std::cout << "Vui Long Chon Tinh Nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				slot = ChonDiem();
				d[slot - 1].Nhap();
				std::cout << "Diem Da Nhap: ";
				d[slot - 1].Xuat();
				break;
			case 2:
				slot = ChonDiem();
				std::cout << "Diem " << slot << ": ";
				d[slot - 1].Xuat();
				break;
			case 3:
				slot = ChonDiem();
				std::cout << "Nhap x va y: ";
				std::cin >> x >> y;
				d[slot - 1].DiChuyen(x, y);
				std::cout << "Diem sau khi di chuyen: ";
				d[slot -1].Xuat();
				break;
			case 4:
				slot = ChonDiem();
				slot1 = ChonDiem();			
				if(d[slot - 1].KiemTraTrungNhau(d[slot1 - 1]))
					std::cout << "Hai diem nay trung nhau!";
				else
					std::cout << "Hai diem nay khong trung nhau";
				break;
			case 5:
				slot = ChonDiem();
				slot1 = ChonDiem();
				std::cout << "Khong cach giua 2 diem la: " << d[slot -1].TinhKhoangCach(d[slot1 - 1]);
				break;
			case 6:
				slot = ChonDiem();
				std::cout << "Diem doi xung qua goc toa do la: ";
				d[slot - 1].DoiXung().Xuat();
				break;
			case 7:
				CV = d[0].TinhChuVi(d[1], d[2]);				
				if (CV == -1)
					std::cout << "Ba diem khong tao thanh tam giac";
				else
					std::cout << "Chu vi tam giac la: " << CV;
				break;
			case 8:
				DT = d[0].TinhChuVi(d[1], d[2]);				
				if (DT == -1)
					std::cout << "Ba diem khong tao thanh tam giac";
				else
					std::cout << "Dien tich tam giac la: " << DT;
				break;
			case 0:
				return 0;
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);

	return 0;
}
