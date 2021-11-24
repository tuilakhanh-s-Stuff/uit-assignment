/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
if
case
:
###End banned keyword*/

//LAM TRON SO THUC
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double x;
    int d;
    cin >> x >> d;
    double result, numRound;
    numRound = pow(10, d);
    result = round(x * numRound) / numRound;
    cout << result;

    return 0;
}


