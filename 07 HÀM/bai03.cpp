/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
else
[
###End banned keyword*/

#include <iostream>

using namespace std;

//GV goi y viet cac ham sau
double larger(double x, double y);
double compareThree(double x, double y, double z);

//###INSERT CODE HERE -
double larger(double x, double y) {
  double max = (x > y) * x + (y > x) * y;
  return max;
}

double compareThree(double x, double y, double z) {
  return larger(x, larger(y, z));
}

int main()
{
    double a,b,c;
    cout<<"Enter 03 numbers:\n";
    cin>>a>>b>>c;
    cout<< "Numbers entered: "<<a<<", "<<b<<", "<<c<<endl;
    cout<<"The largest number is "<< compareThree(a,b,c);
    return 0;
}

