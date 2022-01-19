/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/
#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
struct Diem {
	int x, y;
};

void nhapDSDiem(Diem a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
}

void xuatDSDiem(Diem a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << '(' << a[i].x << ',' << a[i].y << ")\n";
}

Diem diemDoiXungQuaO(Diem a)
{
	Diem b;
	b.x = -a.x;
	b.y = -a.y;
	return b;
}

double calculateDis(Diem a, Diem b)
{
	return sqrt(static_cast<double>(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

Diem khoangCachNhoNhat(Diem a[], int n, Diem M)
{
	Diem min;
	for (int i = 0; i < n; i++)
	{
		if (calculateDis(min, M) > calculateDis(a[i], M))
			min = a[i];
	}
	return min;
}

int main()
{
    Diem a[100];
    int n;
    nhapDSDiem(a,n); // Nhap danh sach cach diem trong mat phang Oxy
    cout<<"Danh sach diem trong mat phang Oxy:\n";
    xuatDSDiem(a,n); // Xuat danh sach cac diem, moi diem tren 1 dong

    Diem M,N;
    cout<<"\nNhap mot diem de kiem tra khoang cach: ";
    cin>>M.x>>M.y;

    N = diemDoiXungQuaO(M);
    cout<<"\nDiem doi xung voi ("<<M.x<<","<<M.y<<") qua goc toa do O: ("<<N.x<<","<<N.y<<")";

    N = khoangCachNhoNhat(a,n,M);
    cout<<"\nDiem co khoang cach ngan nhat toi ("<<M.x<<","<<M.y<<"): ("<<N.x<<","<<N.y<<")";


    return 0;
}
