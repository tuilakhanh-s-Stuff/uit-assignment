/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
###End banned keyword*/
 
#include <iostream>
 
using namespace std;
 
//###INSERT CODE HERE -
typedef struct PhanSo
{
	int tu, mau;
} PS;

struct DIEM
{
	float x, y;
};

struct VECTOR
{
	float x, y, z;
};

struct sngaysinh
{
	int ngay;
	char thang[100];
	int nam;
};

struct nhancong
{
	char ten[100];
	char diachi[100];
	float bacluong;
	sngaysinh ngaysinh;

};

int main()
{
    string test;cin>>test;
	
    PhanSo a={1,2}; PS b;
    cout<<a.tu<<"/"<<a.mau<<endl;
 
    DIEM M = {0.5,0.7};
    cout<<"("<<M.x<<","<<M.y<<")"<<endl;
 
    VECTOR P = {1.2,0.3,1};
    cout<<"P("<<P.x<<","<<P.y<<","<<P.z<<")"<<endl;
 
    nhancong nguoi_a ={"Hoang Nam","TP HCM",3.4,10,"Mot",1999} , nguoi_b ={"Thuy Van","Dong Nai",4,21,"Muoi Hai",1990}; // 1. T?o 2 nhân công ng??i a, ng??i b
    cout << nguoi_a.ten;		// 2. Xu?t tên c?a ng??i a
    float S = nguoi_a.bacluong + nguoi_b.bacluong;//	3. C?ng b?c l??ng c?a ng??i a và ng??i b
    cout<<nguoi_b.ngaysinh.nam; //4. Xu?t ngày sinh c?a ng??i b 
 
 
 
    return 0;
}
