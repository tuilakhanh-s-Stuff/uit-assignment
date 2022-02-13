
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;



int main()
{
    int n, a[100];

    //###INSERT CODE HERE -
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    bool check = true;
    for (int i = 0; i < n; i++) {
      if ((a[i] % 2) != 0) {
        check = false;
        break;
      }
    }
    if (check) {
      std::cout << "yes";
    } else {
      std::cout << "no";
    }




    return 0;
}
