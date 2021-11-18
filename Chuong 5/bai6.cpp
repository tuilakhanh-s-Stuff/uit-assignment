#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
 
int main() {
 
    double a, b, c;
    double delta, x1, x2;
    cin >> a >> b >> c;
    delta = b*b - 4*a*c;
    if (a == 0) {
      if (b == 0) {
        if (c == 0){
          cout << "INF";
        } else {
          cout << "IE";
        }
      } else {
        x1 = -c/b;
        if (x1 == -0)
          x1 = 0;
        cout << x1; 
      }
    } else {
        if(delta > 0) {
          x1 = (-b+sqrt(delta))/(2*a);
          x2 = (-b-sqrt(delta))/(2*a);
          if (x1 > x2)
            swap(x1, x2);
          cout << x1 << ' ' << x2;
        } else if ( delta < 0) {
          cout << "IE";
        } else {
          x1 = -b/(2*a);
          if (x1 == -0)
            x1 = 0;
          cout << x1 << ' ' << x1; 
        }
    }
    return 0;
}
