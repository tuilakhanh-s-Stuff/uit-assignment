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
void listWord(char a[])
{
	char world2D[100][100];
	int i = 0;
	for (int j = 0, k = 0; j < strlen(a); j++) {
    if (a[j] == ' ') {
      world2D[i++][k] = '\0';
      k = 0;
    } else {
      world2D[i][k++] = a[j];
    }
  }
	for (int j = 0; j <= i; j++)
	{
		cout << world2D[j] << '\n';
	}
}

int main()
{

   char str[100];
   cin.getline(str,100);
   listWord(str);

   return 0;
}
