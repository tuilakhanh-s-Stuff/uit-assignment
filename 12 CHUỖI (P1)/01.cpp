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

//###INSERT CODE HERE
void encloseInBrackets(char a[])
{
  char b[100];
  strcpy(b, a);
  const char *open_brace = "(";
  const char *close_brace = ")";
  strcpy(a, open_brace);
  strcat(a, b);
  strcat(a, close_brace);
}

int main ()
{
    char a[100];
    cin.getline(a,40);
    encloseInBrackets(a);
    cout<<a;
    return 0;
}
