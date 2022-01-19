/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

//###INSERT CODE HERE -
void Nhap(char a[])
{
	cin.getline(a, 35);
}

void Nhap(SinhVien a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].MASV;
		cin.ignore();
		cin.getline(a[i].HoTen, 35);
		cin.getline(a[i].NgaySinh, 35);
		cin >> a[i].GioiTinh;
		cin >> a[i].DiemToan >> a[i].DiemLy >> a[i].DiemHoa;
		a[i].DTB = (a[i].DiemToan + a[i].DiemLy + a[i].DiemHoa) / 3;
	}
}

void XoaTheoHoTen(SinhVien a[], int &n, char hoten[])
{
	int j = 0;
	for (int i = 0; i < n; i++)
    	if (strcmp(a[i].HoTen, hoten) != 0)
        	a[j++] = a[i];
	n = j;
}

void Xuat(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].MASV << '\t';
		cout << a[i].HoTen << '\t';
		cout << a[i].NgaySinh << '\t';
		cout << a[i].GioiTinh << '\t';
		cout << a[i].DiemToan << '\t' << a[i].DiemLy << '\t' << a[i].DiemHoa << '\t';
		cout << setprecision(3) << a[i].DTB;
		cout << '\n';
	}
}

int main() {
    SinhVien A[MAXN];
    char hoTenCanXoa[100];
    int n;

    Nhap(hoTenCanXoa);

    Nhap(A, n);

    XoaTheoHoTen(A, n, hoTenCanXoa);

    Xuat(A, n);
    return 0;
}
