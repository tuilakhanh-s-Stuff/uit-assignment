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
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1, 254);
	cin.getline(s2, 254);
	bool kt = myStrcat(s1, s2);

//###INSERT CODE HERE -
	cout << (kt ? s1 : "Khong noi duoc. Khong du bo nho.");
	return 0;
}

int myStrlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

bool myStrcat(char s1[], char s2[])
{
	int i = myStrlen(s1);
	int j = myStrlen(s2);
	if (i + j > 254)
		return false;
	// s1[i] = ' ';
	// i++;
	for (j = 0; s2[j] != 0; i++, j++)
		s1[i] = s2[j];
	s1[i] = '\0';
	return true;
}
