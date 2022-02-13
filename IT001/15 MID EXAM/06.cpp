/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported define
include
class
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

bool LaSNT(int n);
int SNTthuN(int n);

int main()
{
    int n;     
    cin >> n; 
    cout << SNTthuN(n) << endl;
    return 0;
}

//###INSERT CODE HERE -

bool LaSNT(int n)
{
	if (n < 2)
		return false;
	
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	
	return true;
}

int SNTthuN(int n)
{
	if (n <= 0)
		return -1;
	int count = 0, i = 1;
	while (count != n)
	{
		i++;
		if (LaSNT(i))
			count++;
	}
	return i;
}
