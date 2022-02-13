/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
for
###End banned keyword*/
#include <iostream>
#include <math.h>

using namespace std;



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int x;

    cin >> x;

    bool positive = 1;
    int temp;
    if (x < 0) {
      temp = x * -1;
      positive = 0;
    } else
      temp = x;
    int digits = floor(log10(temp)) + 1;
    if (x == 0)
      digits = 1;
    int i = 0, pows;
    while (i <= digits - 1){
      pows = pow(10, i);
      cout << temp / pows % 10 << '\n';
      i++;
    }
    if (!(positive))
      cout << '-';

    return 0;
}
