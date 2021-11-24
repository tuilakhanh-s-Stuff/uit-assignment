/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
switch
:
###End banned keyword*/


/*Program: Compare numbers
This program compares two integers and outputs the larges*/

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cout<<"Enter any two integers: ";
    cin>>num1>>num2;
    cout<<endl;

    cout<<"The two integers entered are "<<num1<<" and "<<num2<<"\n";
    if (num1 > num2) {
      cout<<"The larger number is "<<num1;
    } else if (num1 < num2) {
      cout<<"The larger number is "<<num2;
    } else {
      cout<<"Both numbers are equal";
    }

    return 0;
}


