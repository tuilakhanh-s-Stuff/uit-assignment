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

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	cin.getline(s, 299);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);

	return 0;
}

//###INSERT CODE HERE -
int myStrcmp(char s1[], char s2[])
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return 0;
	return s1[i] < s2[i] ? -1 : 1;
}

void removeDupli(char s[])
{
	int index = 0;
	int j;
  for (int i=0; s[i] != '\0'; i++)
	{
		for (j=0; j<i; j++)
			if (s[i] == s[j])
				break;

    if (j == i)
    	s[index++] = s[i];
	}
	s[index] = '\0';
}

void DemKyTu(char s[])
{
	int TanSo[100] = {0};

	for (int i = 0; s[i] != 0; i++)
	{
		TanSo[s[i] - ' ']++;
	}

	char c;
	removeDupli(s);
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (TanSo[s[i] - ' '] != 0)
		{
			c = s[i];
				cout << c << ": " << TanSo[s[i] - ' '] << '\n';
		}
	}
}
