/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;



void horizontal_invert(

//###INSERT CODE HERE -
int array[][1000], int rows, int columns)
{
	int temp;
	for (int column = 0; column < columns; column++)
	{
		for (int row = 0; row < rows/2; row++)
		{
			// cout << rows << ' ' << columns << '\n';
			temp = array[row][column];
			array[row][column] = array[rows-1-row][column];
			array[rows-1-row][column] = temp;
		}
	}
}

void input(int a[1000][1000], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}

void output(int a[1000][1000], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int main()
{
    int n, m;
    cin >> n >> m;

    
    int a[1000][1000];
    
    input(a, n, m); //Hàm này đã được code chuẩn không thể chỉnh, sinh viên không cần quan tâm
    
    horizontal_invert(a, n, m);

    output(a, n, m);//Hàm này đã được code chuẩn không cần chỉnh, sinh viên không cần quan tâm
    
    return 0;
}
