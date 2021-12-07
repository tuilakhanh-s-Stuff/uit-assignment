/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
do
if
else
switch
case
define
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

int main() {

  int x, result;
  std::cin >> x;

  result = (x % 2 == 0) ? 0 : 1;
  std::cout << result;

  return 0;
}
