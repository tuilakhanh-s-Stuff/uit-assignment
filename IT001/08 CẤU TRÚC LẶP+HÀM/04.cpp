/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
Fibo
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
	int x;
	cin >> x;
	if (x < 1 || x>30)
		cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
	else
	{
		cout << Fibo(x) << endl;
	}
	return 0;
}

int Fibo(int x)
{
//###INSERT CODE HERE 
  int Alpha = 1, Beta = 1, Total = 1;
  for (int i = 3; i <= x; i++) {
    Total = Alpha + Beta;
    Alpha = Beta;
    Beta = Total;
  }
  return Total;
}
