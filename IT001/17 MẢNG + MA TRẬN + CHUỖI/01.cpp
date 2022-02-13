/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//###INSERT CODE HERE -
void Chuanhoa(char s[])
{
	int n = strlen(s);
	if ('a' <= s[0] && s[0] <= 'z')
    s[0] = s[0] - 32;
  for (int i = 1; i < n; i++)
  {
    if ('A' <= s[i] && s[i] <= 'Z')
      s[i] = s[i] + 32;
    if (s[i-1] == ' ' && 'a' <= s[i] && s[i] <= 'z')
      s[i] = s[i] - 32; 
  }
	int i, j;
	for (i = j = 0; i < n; ++i)
	{
		if (s[i] != ' ' || (s[i - 1] != ' ' && i > 0))
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

int main()
{
	char s[1000];
	cin.getline(s, 1000);
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}
