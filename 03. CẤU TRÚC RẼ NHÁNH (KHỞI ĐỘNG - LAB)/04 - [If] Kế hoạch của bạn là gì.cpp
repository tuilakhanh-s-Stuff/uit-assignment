/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
switch
:
###End banned keyword*/


/*Program: What is your plan today? */

#include <iostream>

using namespace std;

int main()
{
    int temperature;
    cout<<"What is the outdoor temperature? ";
    cin>>temperature;
    cout<<endl;
    
    cout<<"What is your plan today?\n";
    
    if (temperature >= 33)
      cout<<"Good day for swimming";
    else if (24 <= temperature && temperature < 33)
      cout<<"Good day for golfing";
    else if (10 <= temperature && temperature < 24)
      cout<<"Good day to play tennis";
    else if (temperature < 10)
      cout<<"Go to bed";  

    return 0;
}


