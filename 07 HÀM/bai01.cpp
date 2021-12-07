/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
else
[
###End banned keyword*/

#include <iostream>

using namespace std;

int sumTwo(int a, int b)
{

//###INSERT CODE HERE -
  return a + b;
}

int main() {

  int x, y;
  cin >> x >> y;

  cout << "The sum of " << x << " and " << y << " is " << sumTwo(x, y);

  return 0;
}


