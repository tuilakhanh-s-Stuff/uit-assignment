/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

#define MAX 500

void Nhapmang(int a[], int &n);
void Xuatmang(int a[], int n);
long long TichSole_VTSNT(int a[], int n);


int main()
{
    int a[MAX], n;
    Nhapmang(a,n);

//###INSERT CODE HERE -
	if (n < 1)
	{
		cout << "Mang rong.";
		return 0;
	}
	Xuatmang(a, n);
	long long sum = TichSole_VTSNT(a, n);
	if (sum == 0)
		cout << "\nKhong tim duoc so le o vi tri la so nguyen to, tich la: 0";
	else
		cout << "\nTich cac so le o vi tri la so nguyen to la: " << sum;
	return 0;
}

void Nhapmang(int a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}

bool isPrimes(int a)
{
	if (a == 0 || a == 1)
		return false;
	for (int i = 2; i < a; i++)
		if (a % i == 0)
			return false;
	return true;
}

long long TichSole_VTSNT(int a[], int n)
{
	long long sum = 1;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if ((a[i] % 2 != 0) && isPrimes(i))
		{
			flag = true;
			sum *= a[i];
		}
	}
	if (flag == false)
		return 0;
	return sum;
}
