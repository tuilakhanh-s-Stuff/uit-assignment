/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
;
###End banned keyword*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    double x;


    cin >> x;
    cout << 
      setprecision(15) << (2.0 * x * M_PI) << '\n' << x * x * M_PI
    << endl;
    return 0;
}
