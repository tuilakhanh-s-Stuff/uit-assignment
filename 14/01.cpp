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

//###INSERT CODE HERE -
int myStrlen(char a[])
{
	int i;
	for(i = 0; a[i] != '\0'; i++);
	return i;
}

bool check(char a[])
{
	for (int i = 0; i < myStrlen(a); i++)
		if (48 <= a[i] && a[i] <= 57)
			return false;
	return true;
}

int main()
{
	char a[100000];
	cin.getline(a, 100000);
	cout << (check(a) ? a : "CHUOI KHONG HOP LE.");
	return 0;
}
