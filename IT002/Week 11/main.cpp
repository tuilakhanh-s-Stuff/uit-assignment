#include <iostream>
#include "Diem3C.h"
#include "DiemMau3C.h"
#include "Diem3CMau.h"
#include "DiemMau.h"

int ChonDiem()
{
	int slot;
	std::cout << "Chon 1 trong 3 diem: ";
	std::cin >> slot;
	return slot;
}

void MenuBai1() {
	Diem3C *d = new Diem3C[3];
	int choose;
	int slot, slot1;
	double CV, DT;
	double x, y, z;
	do {	
		system("clear");
		std::cout << "----------Chuong trinh tinh toan Diem----------\n";
		std::cout << "1. Nhap Diem3C\n";
		std::cout << "2. Xuat Diem3C\n";
		std::cout << "3. Di Chuyen Diem3C\n";
		std::cout << "4. Kiem Tra 2 Diem3C Co Toa Do Trung Nhau\n";
		std::cout << "5. Tinh Khoang Cach Giua 2 Diem3C\n";
		std::cout << "6. Diem3C Doi Xung Qua Goc Toa Do\n";
		std::cout << "7. Chu Vi Tam Giac Qua 3 Diem3C\n";
		std::cout << "8. Dien Tich Tam Giac Qua 3 Diem3C\n";
		std::cout << "0. Thoat Chuong Trinh\n";
		std::cout << "Vui Long Chon Tinh Nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				slot = ChonDiem();
				d[slot - 1].Nhap();
				std::cout << "Diem3C Da Nhap: ";
				d[slot - 1].Xuat();
				break;
			case 2:
				slot = ChonDiem();
				std::cout << "Diem3C " << slot << ": ";
				d[slot - 1].Xuat();
				break;
			case 3:
				slot = ChonDiem();
				std::cout << "Nhap x, y va z: ";
				std::cin >> x >> y >> z;
				d[slot - 1].DiChuyen(x, y, z);
				std::cout << "Diem3C sau khi di chuyen: ";
				d[slot -1].Xuat();
				break;
			case 4:
				slot = ChonDiem();
				slot1 = ChonDiem();			
				if(d[slot - 1].KiemTraTrungNhau(d[slot1 - 1]))
					std::cout << "Hai Diem3C nay trung nhau!";
				else
					std::cout << "Hai Diem3C nay khong trung nhau";
				break;
			case 5:
				slot = ChonDiem();
				slot1 = ChonDiem();
				std::cout << "Khong cach giua 2 Diem3C la: " << d[slot -1].TinhKhoangCach(d[slot1 - 1]);
				break;
			case 6:
				slot = ChonDiem();
				std::cout << "Diem3C doi xung qua goc toa do la: ";
				d[slot - 1].DoiXung().Xuat();
				break;
			case 7:
				CV = d[0].TinhChuVi(d[1], d[2]);				
				if (CV == -1)
					std::cout << "Ba Diem3C khong tao thanh tam giac";
				else
					std::cout << "Chu vi tam giac la: " << CV;
				break;
			case 8:
				DT = d[0].TinhChuVi(d[1], d[2]);				
				if (DT == -1)
					std::cout << "Ba Diem3C khong tao thanh tam giac";
				else
					std::cout << "Dien tich tam giac la: " << DT;
				break;
			case 0:
				return;
 	 	    default:
				std::cout << "Moi ban chon lai !!! " << std::endl;
       	 	 	break;
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);
}

void MenuBai2() {
	DiemMau3C *d = new DiemMau3C[3];
	int choose;
	int slot, slot1;
	double CV, DT;
	double x, y, z;
	do {	
		system("clear");
		std::cout << "----------Chuong trinh tinh toan Diem----------\n";
		std::cout << "1. Nhap DiemMau3C\n";
		std::cout << "2. Xuat DiemMau3C\n";
		std::cout << "3. Kiem Tra 2 DiemMau3C Trung Nhau\n";
		std::cout << "0. Thoat Chuong Trinh\n";
		std::cout << "Vui Long Chon Tinh Nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				slot = ChonDiem();
				d[slot - 1].Nhap();
				std::cout << "DiemMau3C Da Nhap: ";
				d[slot - 1].Xuat();
				break;
			case 2:
				slot = ChonDiem();
				std::cout << "DiemMau3C " << slot << ": ";
				d[slot - 1].Xuat();
				break;
			case 3:
				slot = ChonDiem();
				slot1 = ChonDiem();			
				if(d[slot - 1].KiemTraTrungNhau(d[slot1 - 1]))
					std::cout << "Hai DiemMau3C nay trung nhau!";
				else
					std::cout << "Hai DiemMau3C nay khong trung nhau";
				break;
			case 0:
				return;
 	 	    default:
				std::cout << "Moi ban chon lai !!! " << std::endl;
       	 	 	break;
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);
}

void MenuBai3() {
	DiemMau d[3];
	int choose;
	int slot, slot1;
	double CV, DT;
	double x, y, z;
	do {
		system("clear");
		std::cout << "----------Chuong trinh tinh toan Diem----------\n";
		std::cout << "1. Nhap DiemMau\n";
		std::cout << "2. Xuat DiemMau\n";
		std::cout << "3. Kiem Tra 2 DiemMau Trung Nhau\n";
		std::cout << "0. Thoat Chuong Trinh\n";
		std::cout << "Vui Long Chon Tinh Nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				slot = ChonDiem();
				d[slot - 1].Nhap();
				std::cout << "DiemMau Da Nhap: ";
				d[slot - 1].Xuat();
				break;
			case 2:
				slot = ChonDiem();
				std::cout << "DiemMau " << slot << ": ";
				d[slot - 1].Xuat();
				break;
			case 3:
				slot = ChonDiem();
				slot1 = ChonDiem();		
				if(d[slot - 1].KiemTraTrungNhau(d[slot1 - 1]))
					std::cout << "Hai DiemMau nay trung nhau!";
				else
					std::cout << "Hai DiemMau nay khong trung nhau";
				break;
			case 0:
				return;
 	 	    default:
				std::cout << "Moi ban chon lai !!! " << std::endl;
       	 	 	break;
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);
}

void MenuBai4() {
	Diem3CMau d[3];
	int choose;
	int slot, slot1;
	double CV, DT;
	double x, y, z;
	do {
		system("clear");
		std::cout << "----------Chuong trinh tinh toan Diem----------\n";
		std::cout << "1. Nhap Diem3CMau\n";
		std::cout << "2. Xuat Diem3CMau\n";
		std::cout << "3. Kiem Tra 2 Diem3CMau Trung Nhau\n";
		std::cout << "0. Thoat Chuong Trinh\n";
		std::cout << "Vui Long Chon Tinh Nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				slot = ChonDiem();
				d[slot - 1].Nhap();
				std::cout << "Diem3CMau Da Nhap: ";
				d[slot - 1].Xuat();
				break;
			case 2:
				slot = ChonDiem();
				std::cout << "Diem3CMau " << slot << ": ";
				d[slot - 1].Xuat();
				break;
			case 3:
				slot = ChonDiem();
				slot1 = ChonDiem();		
				if(d[slot - 1].KiemTraTrungNhau(d[slot1 - 1]))
					std::cout << "Hai Diem3CMau nay trung nhau!";
				else
					std::cout << "Hai Diem3CMau nay khong trung nhau";
				break;
			case 0:
				return;
 	 	    default:
				std::cout << "Moi ban chon lai !!! " << std::endl;
       	 	 	break;
		}
		std::cin.ignore();
		std::cin.get();
	} while (true);
}

int main() {
    int choose;
    do {
        system("clear");
        std::cout << "\nVui long chon chuong trinh\n";
        std::cout << "1. Bai 1\n";
        std::cout << "2. Bai 2\n";
        std::cout << "3. Bai 3\n";
		std::cout << "4. Bai 4\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cin >> choose;
        switch (choose) 
        {
            case 0:
                std::cout << "Dang thoat CT...";
                break;
            case 1:
			 	MenuBai1();
                break;
            case 2:
				MenuBai2();
                break;
            case 3:
				MenuBai3();
                break;
			case 4:
				MenuBai4();
				break;
             default:
                std::cout << "Lua chon khong hop le vui long nhap lai!\n";
                system("pause");
                continue;
        }
    } while(choose != 0);
	return 0;
}
