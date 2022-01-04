/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class strlen strcat string strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main() {
  char s[MAX];
  cin.getline(s, 299);
  if (myStrcmp(s, "") == 0)
    cout << "Chuoi rong." << endl;
  else
    DemTieng(s);
  return 0;
}

//###INSERT CODE HERE -
int myStrlen(char s[], int k) {
  int i;
  for (i = k; s[i] != '\0'; i++)
    ;
  return i;
}

void myStrcpy(char s[], int vt, char s1[], int k) {
  int i;
  for (i = 0; s1[i] != '\0'; i++)
    s[i] = s1[i];
  s[i] = '\0';
}

int myStrcmp(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  if (s1[i] == s2[i])
    return 0;
  return s1[i] < s2[i] ? -1 : 1;
}

int WorldNum(char s[]) {
  int count = 0, i = 0;
  while (s[i] != '\0') {
    if (s[i] == ' ') {
      count++;
    }
    i++;
  }
  return count;
}

void ChuanHoa(char s[])
{
	int i, j;
	int n = myStrlen(s, 0);
	for (i = j = 0; i < n; ++i)
	{
		if (s[i] != ' ' || (s[i - 1] != ' ' && i > 0))
		{
			s[j++] = s[i];
		}
	}
	if (s[j - 1] == ' ')
		s[j - 1] = '\0';
	else
		s[j] = '\0';
}

void DemTieng(char s1[]) {
  // world2D contain all world in arrayS, world contain world without dup
	ChuanHoa(s1);
	// cout << s1;
  char world2D[300][300];
  char world[300][300];
  int fullWorldC = WorldNum(s1);
  int worldC = 0;
  int lenght = myStrlen(s1, 0);
  // Split arrayS by world into 2D array
  for (int i = 0, j = 0, k = 0; j < lenght; j++) {
    if (s1[j] == ' ') {
      world2D[i++][k] = '\0';
      k = 0;
    } else {
      world2D[i][k++] = s1[j];
    }
  }
  // World2D remove dup worlds and push into World
  for (int i = 0, j = 0; i <= fullWorldC; i++) {
    for (int k = 0; k <= fullWorldC; k++) {
      // No Dup
      if (i == k) {
        myStrcpy(world[j++], 1, world2D[i], 2);
        worldC++;
      } else {
        if (myStrcmp(world[k], world2D[i]) != 0)
          continue;
        else
          break;
      }
    }
  }
  int freq = 0;
  for (int i = 0; i < worldC; i++) {
    for (int j = 0; j <= fullWorldC; j++) {
      if (myStrcmp(world[i], world2D[j]) == 0)
        freq++;
    }
    cout << world[i] << ": " << freq << '\n';
    freq = 0;
  }
}
