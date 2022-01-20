/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -
struct ngay
{
	int ng, thang, nam;
};

struct HOPSUA
{
	float weight;
	ngay day;
	char name[35];
};

void nhapDSHopSua(HOPSUA a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].weight;
		cin >> a[i].day.ng >> a[i].day.thang >> a[i].day.nam;
		cin.ignore();
		cin.getline(a[i].name, 35);
	}
}

bool compareDay(ngay a, ngay b)
{
	
	if (a.nam < b.nam)
	{
		return false;
	}
	else if (a.nam == b.nam)
	{
		if (a.thang < b.thang)
		{
			return false;
		}
		else if (a.thang == b.thang)
		{
			if (a.ng <= b.ng)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}

int soLuongQuaHan(HOPSUA a[], int n, ngay y)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (compareDay(y, a[i].day))
			count++;
	}
	return count;
}

int main()
{
    HOPSUA a[100];
    int n;
    cout<<"Nhap danh sach hop sua: "<<endl;
    nhapDSHopSua(a,n);// Nhap danh sach cac hop sua
    cout<<"\nNhap ngay kiem tra: "<<endl;
    ngay y;
    cin>>y.ng>>y.thang>>y.nam;
    cout<<"\nSo luong hop sua qua han: "<<soLuongQuaHan(a,n,y);

    return 0;
}
