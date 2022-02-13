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
    int x, pos = -1;
    std::cin >> x;
    for (int i = 0; i < n; i++) {
      if (a[i] == x) {
        pos = i + 1; 
        break;
      }
    }
    if (pos == -1) {
      std::cout << "Khong tim thay " << x;
    } else {
      std::cout << x << " xuat hien dau tien tai vi tri thu " << pos << " trong mang";
    }

    return 0;
}
