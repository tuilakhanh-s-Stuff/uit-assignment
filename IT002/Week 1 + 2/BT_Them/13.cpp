#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
 
    int a, b, c;
    double delta, x1, x2;
    cin>>a>>b>>c;
    delta = b*b - 4*a*c;
    if (a != 0) {
        if(delta > 0) {
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            cout << "PT co hai nghiem phan biet:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2;
        } else if ( delta < 0) {
          cout << "PTVN";
        } else {
            x1 = (double)-b/(2*a);
            cout << "PT co nghiem kep: x1 = x2 = " << x1; 
        }
    }
    else
    {
        if (b == 0) {
        if (c == 0){
          cout << "INF";
        } else {
          cout << "IE";
        }
      } else {
        x1 = -(static_cast<double>(c)/b);
        if (x1 == -0)
          x1 = 0;
        cout << x1; 
      }
    }
    return 0;
}