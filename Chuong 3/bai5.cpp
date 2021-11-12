/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
switch
:
###End banned keyword*/


//Phan loai nhan khau

#include <iostream>

using namespace std;

int main()
{
    int age; cin>>age;
    char gender; cin>>gender;

    if (gender == 'm' || gender == 'M') {
      if (age >= 21) {
        cout<<"1";
      } else if (age < 21) {
        cout<<"3";
      }
    } else if (gender == 'f' || gender == 'F') {
      if (age >= 21) {
        cout<<"2";
      } else if (age < 21) {
        cout<<"4";
      } 
    } else {
      cout<<"I do not know why";
    }
    
    return 0;
}


