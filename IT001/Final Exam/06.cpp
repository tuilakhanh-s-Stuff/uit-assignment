
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -
bool compare(char s)
{
	if ('A' <= s && s <= 'Z')
		s = tolower(s);
	char a[] = "aeoiu";
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] == s)
			return true;
	return false;
	
}

int DemSoKyTuNguyenAm(char s[])
{
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (compare(s[i]))
			count++;
	}
	return count;
}

int main()
{
    char s[256];
    cin.getline(s,256);
    cout<<DemSoKyTuNguyenAm(s);
    return 0;
}
