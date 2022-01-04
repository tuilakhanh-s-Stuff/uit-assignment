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
int countBlankSpace(char a[])
{
  int count = 0;
  for (int i = 0; i < strlen(a); i++)
  {
    if (a[i] == ' ')
      count++;
  }
  return count;
}

void countUpperLower(char a[])
{
  int countUpper = 0, countLower = 0;
  for (int i = 0; i < strlen(a); i++)
    if ('a' <= a[i] && a[i] <= 'z')
      countLower++;
    else if ('A' <= a[i] && a[i] <= 'Z')
      countUpper++;
  cout << "\nSo ky tu hoa: " << countUpper << '\n';
  cout << "So ky tu thuong: " << countLower;
}

int main()
{

   char str[100], str1[100];
   cin.getline(str,100);
   cout<<"Chuoi: "<<str;
   cout<<"\nSo ky tu khoang trang: "<<countBlankSpace(str);
   countUpperLower(str);



   return 0;
}
