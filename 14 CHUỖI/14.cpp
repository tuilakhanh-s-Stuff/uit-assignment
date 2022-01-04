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

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	cin.getline(s,MAX);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}

//###INSERT CODE HERE -
int myStrcmp(char s1[], char s2[])
{
  int i = 0;
  int check = 0;
  while(s1[i] != '\0' && s2[i] != '\0')
  {
    if (s1[i] != s2[i])
    {
      check = 1;
      break;
    }
    i++;
  }
  if (check == 0 && s1[i] == '\0' && s2[i] == '\0')
    return 0;
  else
    return 1; 
}
  
void StringReverse(char a[])
{
  size_t len = 0, i, j;
  while (a[len])
    ++len;
  i = 0, j = len;
  while (i < j--)
  {
    char c = a[i];
    a[i++] = a[j];
    a[j] = c;
  }

  i = 0;
  while (a[i])
  {
    while (a[i] == ' ')
      ++i;

    j = i;
    while (a[j] && a[j] != ' ')
      ++j;

    size_t last = j;
    while (i < j--)
    {
      char c = a[i];
      a[i++] = a[j];
      a[j] = c;
    }

    i = last;
  }
}
