/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <math.h>

using namespace std;


//###INSERT CODE HERE -

bool isPower(int n) {
  if (n == 1)
    return true;
  double j = 2;
  double power;
  for (int i = 2; i <= 18; i++) {/// 1 <= n <= 350   ==> 18^2 = 324, 19^2 = 361
    j = 2;
    do {
      power = pow(i, j);
      if (power == n)
        return true;
      j++;
    } while (power < n);
  }
  return false;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;cin>>n;
    cout << isPower(n)<< endl;
    return 0;
}


