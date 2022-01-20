/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


int main()
{
    int a[10000],n,i;
    cin>>n;
//###INSERT CODE HERE -
	for (i = 0; i < n; i++)
		cin >> a[i];
	
	int j = 0, min = a[0];
	for (i = 1; i < n; i++)
		if (min >= a[i])
		{
			j = i;
			min = a[i];
		}
	cout << min << '\n' << j;

    return 0;
}
