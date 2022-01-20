/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[][100], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
}

void outputMatrix(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int sumRow(int a[100], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

int rowWithMaximumSum(int a[][100], int n)
{
	int maxRow = 0;
	for (int i = 1; i < n; ++i)
	{
		if (sumRow(a[i], n) > sumRow(a[maxRow], n))
			maxRow = i;
	}
	return maxRow;
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    //Tim dong co tong lon nhat trong ma tran
    cout << "Row " <<  rowWithMaximumSum(a,n) << " has max sum "<<endl;

    return 0;
}



