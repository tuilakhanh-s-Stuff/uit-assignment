/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <cctype>
#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -
bool isCharacter(char a)
{
	if ('a' <= a && a <= 'z')
		return true;
	else if ('A' <= a && a <= 'Z')
		return true;
	return false;
}

bool isNum(char a)
{
	if (32 <= a && a <= 64)
		return true;
	return false;
}

bool compareChar(char a, char b)
{
	if ('A' <= a && a <= 'Z')
		a = tolower(a);
	if ('A' <= b && b <= 'Z')
		b = tolower(b);
	return a == b;
}

int SoSanhBangNhau(char a[], char b[])
{
	int n = strlen(a);
	int m = strlen(b);
	if (n != m)
		return false;
	for (int i = 0; i < n; i++)
	{
		if (isCharacter(a[i]) && isCharacter(b[i]))
		{
			if (!(compareChar(a[i], b[i])))
				return 0;
		}
		else if (isNum(a[i]) && isNum(b[i]))
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
    char s[256], t[256];
    cin.getline(s,256);
    cin.getline(t,256);
    cout<<SoSanhBangNhau(s,t);

    return 0;
}
