/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
switch
if
[
###End banned keyword*/


#include <iostream>

using namespace std;

double larger(double x, double y)
{
    if (x>y)
        return x;
    return y;
}


int main()
{
    int n;
    double num, maxNum;
    cin>>n;
    cout<<"Enter "<<n<<" numbers: "<<endl;


//###INSERT CODE HERE -
    cin >> num;
    maxNum = num;
    for (int i = 0; i < n - 1; i++) {
      cin >> num;
      maxNum = larger(num, maxNum);
    }
    cout << "The largest number is "<< maxNum;
}

