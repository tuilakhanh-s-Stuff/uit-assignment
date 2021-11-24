/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
if
switch
:
###End banned keyword*/


//TINH TOAN 2 SO THUC
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a, b;

    cin >> a >> b;
    
    double add, subtract, multiply, devide;
    add = a + b;
    subtract = a - b;
    multiply = round((a * b) * 100) / 100;
    devide = round((a / b) * 100) / 100;

    cout << "(" << a << ") + (" << b << ") = " << add << '\n';
    cout << "(" << a << ") - (" << b << ") = " << subtract << '\n';
    cout << "(" << a << ") * (" << b << ") = " << multiply << '\n';
    cout << "(" << a << ") / (" << b << ") = " << devide;

    return 0;
}


