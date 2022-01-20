
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
for
while
###End banned keyword*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


//###INSERT CODE HERE -
int vitrung(int n)
{
	if (n == 1)
		return 4;
	return 2 * vitrung(n - 1);
}

int goitien(int n)
{
	if (n == 0)
		return 1000;
	return (1 + 0.12) * goitien(n - 1);
}

long long giaithua(int n)
{
	if (n == 0)
		return 1;
	return n * giaithua(n - 1);
}

int fibo(int n)
{
	if (n <= 1)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}

long double luythua(float x, int y)
{
	long double temp; 
    if(y == 0) 
        return 1; 
    temp = luythua(x, y / 2); 
    if (y % 2 == 0) 
        return temp * temp; 
    else
    { 
        if(y > 0) 
            return x * temp * temp; 
        else
            return (temp * temp) / x; 
    } 
}

int ucln_tru(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	if (a == 0)
		return b;
	if (b == 0)
		return a;
	
	if (a == b)
		return a;
	
	if (a > b)
		return ucln_tru(a - b, b);
	return ucln_tru(a, b - a);
}

int ucln_du(int a, int b)
{
	if (b == 0)
		return a;
	return ucln_du(b, a % b);
}

int tohop(int n, int k)
{
	if (n < k)
		return 0;
	if (k == 0 || k == n)
		return 1;
	if (k == 1)
		return n;
	return (tohop(n - 1, k - 1) + tohop(n - 1, k));
}

int main()
{

    int n;
    cout<<"Nhap n: "<<endl;
    cin>>n;
    cout<<"Sau "<<n<<" gio co "<<vitrung(n)<<" con vi trung"<<endl;
    cout<<"Sau "<<n<<" nam, so tien co duoc: "<<goitien(n)<<endl;
    cout<<n<<"!: "<<giaithua(n)<<endl;
    cout<<"Fibo("<<n<<"): "<<fibo(n)<<endl;

    cout<<"Nhap x: "<<endl;
    float x; cin>>x;
    cout<<x<<" luy thua "<<n<< ": "<<setprecision(15)<<luythua(x,n)<<endl;

    cout<<"Nhap a va b: "<<endl;
    int a, b; cin>>a>>b;
    cout<<"Uoc chung lon nhat cua "<<a<<" va "<<b<<": ";
    cout<<ucln_tru(a,b)<<" "<<ucln_du(a,b)<<endl; // Tim UCLN su dung phep chia du hoac phep tru


    cout<<"Nhap k: "<<endl;
    int k; cin>>k;
    cout<<"So luong to hop chap "<<k<<" cua "<<n<<" phan tu: "<<tohop(n,k);


    return 0;
}
