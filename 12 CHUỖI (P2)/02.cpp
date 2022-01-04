/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>
#include <string>

using namespace std;

//###INSERT CODE HERE -
string properNounCorrection(string a)
{
  if ('a' <= a[0] && a[0] <= 'z')
    a[0] = a[0] - 32;
  for (int i = 1; i < a.size(); i++)
  {
    if ('A' <= a[i] && a[i] <= 'Z')
      a[i] = a[i] + 32;
  }
  return a;
}

int main ()
{
    string a;
    getline(cin,a);
    cout<< properNounCorrection(a);
    return 0;
}
