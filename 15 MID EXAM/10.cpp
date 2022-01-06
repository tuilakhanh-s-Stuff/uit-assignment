
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
int countWords(char a[])
{
	int count = 0;
	if (a[0] != ' ')
		count++;
	for (int i = 1; i < strlen(a); i++)
	{
		if (a[i] != ' ' && a[i - 1] == ' ')
		{
			count++;
		}
	}
	return count;
}

int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countWords(s) << endl;
    return 0;
}
