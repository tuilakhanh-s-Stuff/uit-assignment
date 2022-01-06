
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputMatrix(int a[][100], int &n, int &m)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}

int findRow(int a[][100], int n, int m)
{
	int flag = -1;
	int count;
	for (int i = 0; i < n && flag == -1; i++)
	{
		count = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				count++;
		}
		if (count == m)
			flag = i;
	}
	return flag;
}

int main()
{
	int a[100][100],n,m;
	inputMatrix(a, n,m);

	cout<<findRow(a,n,m);

	return 0;
}
