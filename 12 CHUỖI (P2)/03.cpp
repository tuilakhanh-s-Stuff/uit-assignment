/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
class
new
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
string findEmailDomain(string adr)
{
  return adr.substr(adr.find_last_of("@") + 1);
}

int main ()
{
    string address;
    getline(cin,address);
    cout<< findEmailDomain(address);
    return 0;
}
