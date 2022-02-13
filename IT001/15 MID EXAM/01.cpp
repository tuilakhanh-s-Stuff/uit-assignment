
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int car[], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> car[i];
	}
}

long totalFine(int car[], int n, int day, int fine)
{
	int count = 0;
	long total = 0;
	if (day % 2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (car[i] % 2 != 0) 
			{

				count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (car[i] % 2 == 0) count++;
		}
	}
	total = count * fine;
	return total;
}


int main()
{
    int car[100],n;
    inputArray(car,n); // Nhap so luong xe va mang cac bien so xe

    int date; cin>>date; // nhap ngay
    int fine; cin>>fine; //so tien phat cho moi xe khi vi pham, fine = 250

    //Goi ham tinh tong so tien phat thu ve trong ngay
    cout << totalFine(car, n, date, fine);

    return 0;
}
