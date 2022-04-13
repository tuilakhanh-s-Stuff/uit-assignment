#include "Fraction.h"
#include <algorithm>
#include <iostream>

void Input(PhanSo& Frac)
{
    std::cout << "Vui long nhap phan tu: ";
    std::cin >> Frac.TuSo ;
    std::cout << "\nVui long nhap phan mau: ";
    std::cin >> Frac.MauSo;
    std::cout << "\n";
}

void Input(PhanSo& Frac1, PhanSo& Frac2)
{
    std::cout << "Vui long nhap phan tu phan so thu nhat: ";
    std::cin >> Frac1.TuSo ;
    std::cout << "\nVui long nhap phan mau phan so thu nhat: ";
    std::cin >> Frac1.MauSo;
    std::cout << "\nVui long nhap phan tu phan so thu hai: ";
    std::cin >> Frac2.TuSo;
    std::cout << "\nVui long nhap phan mau phan so thu hai: ";
    std::cin >> Frac2.MauSo;
    std::cout << "\n";
}

void Output(PhanSo Frac)
{
    if (Frac.MauSo == 0)
        std::cout << "Khong thoa yeu cau bai toan";
    else if (Frac.MauSo < 0)
        std::cout << -1 * Frac.TuSo << '/' << -1 * Frac.MauSo;
    else if ((Frac.TuSo % Frac.MauSo) == 0)
        std::cout << Frac.TuSo / Frac.MauSo;
    else
        std::cout << Frac.TuSo << '/' << Frac.MauSo;
    std::cout << '\n';
}

void reduceFrac(PhanSo& Frac)
{
    int ucln = std::__gcd(Frac.TuSo, Frac.MauSo);
	Frac.TuSo = Frac.TuSo / ucln;
	Frac.MauSo = Frac.MauSo / ucln;
}

PhanSo MAX(PhanSo a, PhanSo b){
    double x = static_cast<double>(a.TuSo) / a.MauSo;
	double y = static_cast<double>(b.TuSo) / b.MauSo;
	if (x <= y)
		return b;
    return a;
}

PS add(PS fac1, PS fac2)
{
	PS sum;
	sum.TuSo = fac1.TuSo*fac2.MauSo + fac1.MauSo*fac2.TuSo;
	sum.MauSo = fac1.MauSo*fac2.MauSo;
    reduceFrac(sum);
	return sum;
}

PS subtract(PS fac1, PS fac2)
{
	PS sub;
	sub.TuSo = fac1.TuSo*fac2.MauSo - fac1.MauSo*fac2.TuSo;
	sub.MauSo = fac1.MauSo*fac2.MauSo;
    reduceFrac(sub);
	return sub;
}

PS multiply(PS fac1, PS fac2)
{
	PS mul;
	mul.TuSo = fac1.TuSo * fac2.TuSo;
	mul.MauSo = fac1.MauSo * fac2.MauSo;
    reduceFrac(mul);
	return mul;
}

PS divide(PS fac1, PS fac2)
{
	PS div;
	div.TuSo = fac1.TuSo * fac2.MauSo;
	div.MauSo = fac1.MauSo * fac2.TuSo;
    reduceFrac(div);
	return div;
}

void Fraction_Program()
{
    PhanSo Frac1, Frac2;
    bool has1Frac = false, has2Frac = false;
    int choose;
    do {
        std::system("cls");
        std::cout << "\n--------------------Chuong trinh xy ly phan so--------------------\n";
        std::cout << "1. Nhap mot phan so\n";
        std::cout << "2. Nhap hai phan so\n";
        std::cout << "3. Rut gon mot phan so\n";
        std::cout << "4. Rut gon hai phan so\n";
        std::cout << "5. Xuat mot phan so\n";
        std::cout << "6. Xuat hai phan so\n";
        std::cout << "7. Tim phan so lon hon\n";
        std::cout << "8. Cong hai phan so\n";
        std::cout << "9. Tru hai phan so\n";
        std::cout << "10. Nhan hai phan so\n";
        std::cout << "11. Chia hai phan so\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "---------------------------------------------------------------------\n";
        std::cout << "Lua chon chua ban: ";
        std::cin >> choose;
        std::cout << "\n";
        switch(choose)
        {
            case 0:
                std::cout << "Dang thoat CT...\n";
                break;
            case 1:
                Input(Frac1);
                std::cout << "Phan so vua nhap la: ";
                Output(Frac1);
                has1Frac = true;
                std::cout << '\n';
                break;
            case 2:
                Input(Frac1, Frac2);
                std::cout << "Phan so thu nhat la: ";
                Output(Frac1);
                std::cout << "\nPhan so thu hai la: ";
                Output(Frac2);
                has2Frac = true;
                std::cout << '\n';
                break;
            case 3:
                if(!has1Frac)
                {
                    std::cout << "Vui long nhap mot phan so.";
                    break;
                }
                reduceFrac(Frac1);
                std::cout << "Phan so sau khi rut gon: ";
                Output(Frac1);
                std::cout << '\n';
            case 4:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                reduceFrac(Frac1);
                reduceFrac(Frac2);
                std::cout << "Phan so thu nhat sau khi rut gon: ";
                Output(Frac1);
                std::cout << "\nPhan so thu hai sau khi rut gon: ";
                Output(Frac2);
                std::cout << '\n';
                break;
            case 5:
                if(!has1Frac)
                {
                    std::cout << "Vui long nhap mot phan so.";
                    break;
                }
                std::cout << "Phan so thu nhat la: ";
                Output(Frac1);
                std::cout << '\n';
                break;
            case 6:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Phan so thu nhat la: ";
                Output(Frac1);
                std::cout << "\nPhan so thu hai la: ";
                Output(Frac2);
                std::cout << '\n';
                break;
            case 7:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Phan so lon hon la: ";
                Output(MAX(Frac1, Frac2));
                std::cout << '\n';
                break;
            case 8:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Ket qua cong hai phan so: ";
                Output(add(Frac1, Frac2));
                std::cout << '\n';
                break;
            case 9:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Ket qua tru hai phan so: ";
                Output(subtract(Frac1, Frac2));
                std::cout << '\n';
                break;
            case 10:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Ket qua nhan hai phan so: ";
                Output(multiply(Frac1, Frac2));
                std::cout << '\n';
                break;
            case 11:
                if(!has2Frac)
                {
                    std::cout << "Vui long nhap hai phan so.";
                    break;
                }
                std::cout << "Ket qua chia hai phan so: ";
                Output(divide(Frac1, Frac2));
                std::cout << '\n';
                break;
            default:
                std::cout << "Lua chon khong hop le vui long nhap lai!\n";
                system("pause");
                continue;
        }
        system("pause");
    } while(choose != 0);
}