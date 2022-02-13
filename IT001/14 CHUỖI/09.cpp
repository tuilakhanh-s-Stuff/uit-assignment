/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k); //Ham tra ve chieu dai chuoi s ke tu vi tri k
void myMemmove(char s[], int vt, int k); //Xoa k ky tu trong chuoi s, bat dau tu vi tri vt.
int myStrstr(char s[], char s1[]); //Tim chuoi s1 trong chuoi s, neu tim thay tra ve vi tri s1[0] trong chuoi s, khong tin thay tra ve -1
void Chuanhoa(char s[]);

int main()
{
	char s[MAX];
	cin.getline(s, 299);	//Nhap chuoi s
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}

//###INSERT CODE HERE -

int myStrlen(char s[], int k)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

void Chuanhoa(char s[])
{
	int n = myStrlen(s, 0);
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
