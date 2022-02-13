
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void printArray(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

void removeDups(int a[], int n)
{
	int index = 0;
	int j;
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			if (a[i] == a[j])
				break;
		if (i == j)
		{
			a[index++] = a[i];
		}
	}
	for (int i = 0; i < index; i++)
		cout << a[i] << ' ';	
}

int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
