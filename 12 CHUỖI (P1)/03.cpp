
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
int countLetters(char a[])
{
  int count = 0;
  for (int i = 0; i < strlen(a); i++)
    if (a[i] == 'f' || a[i] == 'F' || a[i] == 'w' || a[i] == 'W' || a[i] == 'j' || a[i] == 'J' || a[i] == 'Z' || a[i] == 'Z')
      count++;
  return count;
}

int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countLetters(s) << endl;
    return 0;
}
