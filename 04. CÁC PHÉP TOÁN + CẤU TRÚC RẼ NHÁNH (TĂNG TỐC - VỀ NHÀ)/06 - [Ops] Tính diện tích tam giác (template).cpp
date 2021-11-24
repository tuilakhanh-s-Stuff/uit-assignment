/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
if
switch
:
###End banned keyword*/


//DIEN TICH TAM GIAC
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
    double p, S;
    p = static_cast<double>(a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    S = round(S * 100) / 100;
    cout << S;

    return 0;
}

