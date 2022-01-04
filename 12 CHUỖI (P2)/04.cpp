
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";

//###INSERT CODE HERE -
    cin.getline(s1, 200);
    int i;
    for (i = 0; i < strlen(s1); i++)
    {
      if (i % 2 == 0)
      {
        if ('a' <= s1[i] && s1[i] <= 'z')
          s2[i] = toupper(s1[i]);
        else
          s2[i] = s1[i];
      }
      else
      {
        if ('A' <= s1[i] && s1[i] <= 'Z')
          s2[i] = tolower(s1[i]);
        else
          s2[i] = s1[i];
      }
    }
    s2[i] = '\0';

    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}
