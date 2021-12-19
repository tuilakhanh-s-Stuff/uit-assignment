
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
int ham_x(int a[], int n)
{
  string s = "";
  for (int i = 0; i < n; i++)
  {
    s += to_string(a[i]);
  }
  return s.length();
}

int main()
{
    int n, a[1000000], dem = 0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    cout << ham_x(a,n);

    return 0;
}
