/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
bool isRepeat(string s)
{
	int n = s.size() / 2;
	if (s.size() % 2 != 0)
		return false;
	else
	{
		string suba = s.substr(0, n);
		string subb = s.substr(n, n);
		if (suba == subb)
			return true;
		else
			return false;
	}
}

int main ()
{
    string inputString;
    getline(cin,inputString);
    cout<< isRepeat(inputString) ;
    return 0;
}
