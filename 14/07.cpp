/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
string
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

//###INSERT CODE HERE -
void upperFirstWorld(char s[])
{
	if ('a' <= s[0] && s[0] <= 'z')
    s[0] = toupper(s[0]);
  for (int i = 1; i < strlen(s); i++)
  {
    if ('A' <= s[i] && s[i] <= 'Z')
      s[i] = tolower(s[i]);
    if (s[i-1] == ' ' && 'a' <= s[i] && s[i] <= 'z')
      s[i] = toupper(s[i]);
  }
}

void eraseExtraSpace(char s[])
{
	int len = strlen(s);
	while(s[0] == ' ')
		strcpy(&s[0], &s[1]);
	while(s[len-1] == ' ')
		s[len-1] = '\0';
	for (int i = 0; i < len; i++)
		if (s[i] == ' ' && s[i+1] == ' ')
		{
			strcpy(&s[i], &s[i+1]);
			i--;
		}
}

void Chuanhoa(char s[])
{
	upperFirstWorld(s);
	eraseExtraSpace(s);
}

int main()
{
	char s[MAX];
	cin.getline(s, 299);
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}
