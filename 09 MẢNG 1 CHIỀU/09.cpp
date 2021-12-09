
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

  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] % 2) == 0) {
      even++;
    } else {
      odd++;
    }
  }
  int check;
  if (n == 0) {
    check = 0;
  } else if (even == n) {
    check = 1;
  } else if (odd == n) {
    check = 2;
  } else
    check = 3;

  switch(check) {
    case 0:
      std::cout << "Mang rong";
      break;
    case 1:
      std::cout << "Mang chua toan so chan";
      break;
    case 2:
      std::cout << "Mang chua toan so le";
      break;
    case 3:
      std::cout << "Mang khong chua toan so chan hay so le";
      break;
  }

    return 0;
}
