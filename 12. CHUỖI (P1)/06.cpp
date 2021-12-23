/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
using namespace std;

//###INSERT CODE HERE -
void replaceChar(char s1[], char s2[], char x)
{
  for (int i = 0; i < strlen(s1); i++)
    for (int j = 0; j < strlen(s2); j++)
      if (s1[i] == s2[j])
        s1[i] = x;
}

int main()
{

   char s1[100],s2[100];
   cin.getline(s1,100);
   cin.getline(s2,100);
   // Thay nhung ky tu trong s1 ma co chua trong s2 thanh '*'
   replaceChar(s1, s2, '*');
   cout<<s1;

   return 0;
}
