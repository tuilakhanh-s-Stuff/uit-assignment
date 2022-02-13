/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


void inputMatrix(int a[][100], int &n);

void outputMatrix(int a[][100], int n);

/* Ham kiem tra ma tran cheo
 La ma tran cheo neu moi phan tu nam ben ngoai duong cheo chinh deu bang 0*/
int isDiagonalMatrix(int a[][100], int n);

/*Ham kiem tra ma tran don vi
La ma tran don vi neu moi phan tu tren duong cheo chinh bang 1
va tat ca cac phan tu khac deu bang 0
Ma tran don vi cung la truong hop dac biet cua ma tran cheo*/
int isIdentityMatrix(int a[][100], int n);


int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

//###INSERT CODE HERE -
	if (isDiagonalMatrix(a, n))
	{
		if (isIdentityMatrix(a, n))
			cout << "a is called a identity matrix";
		else
			cout << "a is called a diagonal matrix";
	}
	return 0;
}

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

int isDiagonalMatrix(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != 0 || a[j][i] != 0)
				return 0;
	return 1;
}

int isIdentityMatrix(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i][i] != 1)
			return 0;
	return 1;
}
