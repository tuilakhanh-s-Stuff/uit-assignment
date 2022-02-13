/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void outputArray(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}

bool isSquare(int n)
{
	int i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return true;
		++i;
	}
	return false;
}

bool isTotalSquare(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i ++)
		if (isSquare(a[i]))
			count++;
	if (count == n)
		return true;
	else return false;
}

int maxSquare(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i] && isSquare(a[i]))
			max = a[i];
	}
	return max;
}

int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;
    if (isTotalSquare(a,n)==1)
    {
        cout <<"Mang toan so chinh phuong"<<endl;
        cout << "So chinh phuong lon nhat: "<<maxSquare(a,n);
    }
    else cout<<"Mang khong phai chua toan cac so chinh phuong";


    return 0;
}
