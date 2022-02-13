/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
class
string
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

//###INSERT CODE HERE -
void insertDot (char s[], int i)
{
	int n = strlen(s);
	memmove(s + i + 1, s + i, n - i - 0);
	s[i + 1] = ' ';
}

bool isURL(char s[], int i)
{
	if (s[i + 3] == '.' || s[i + 3] == '/')
		return true;
	else
		return false;
}

void Chuanhoa(char s[])
{
	int i, j;
	for (i = j = 0; i < strlen(s); ++i)
	{
		if ( (s[i] != ' ' && s[i] != '.') || (s[i - 1] != ' ' && s[i - 1] != '.' && i > 0) )
		{
			s[j++] = s[i];
		}
		else if (s[i] == '.')
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' && s[i+1] == '.')
		{
			s[i] = '.';
			s[i+1] = ' ';
		}
		else if (s[i] == '.' && s[i - 1] != ' ' && s[i+1] != ' ')
		{
			insertDot(s, i);
			// cout << i << ' ' << j << '\n';
			s[++j] = '\0';
		}
	}
}

int main()
{
	char s[MAX];
	cin.getline(s, 299);

	char s1[MAX];
	strcpy(s1, s);
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}

