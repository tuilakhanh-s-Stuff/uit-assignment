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

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	cin.getline(s, 299);
	cin.getline(s1, 299);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{

//###INSERT CODE HERE -
		ChenChuoiTaiVitriK(s, s1, k);
		cout << s;
	}
}

int myStrlen(char s[], int k)
{
	int i;
	for (i = k; s[i] != '\0'; i++);
	return i;
}

void myStrcpy(char s[], int vt, char s1[], int k)
{
	int i;
	for (i = 0; i < k; i++)
		s1[i] = s[i+vt];
	s1[i] = '\0';
}

bool myStrcat(char s1[], char s2[])
{
	int i = myStrlen(s1, 0);
	int j = myStrlen(s2, 0);
	if (i + j > 254)
		return false;
	for (j = 0; s2[j] != 0; i++, j++)
		s1[i] = s2[j];
	s1[i] = '\0';
	return true;
}

void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
	char c[MAX];
	int len = myStrlen(s, k);
	myStrcpy(s, k, c, len);
	myStrcpy(s, 0, s, k);
	myStrcat(s, s1);
	myStrcat(s, c);
}
