/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;


//###INSERT CODE HERE -
int isSumOfConsecutive(int n) {
  int count = 0;
  int sum = 0;
  for (int i = 1; (i + i + 1) <= n; i++) {
    sum = i;
    for (int j = i + 1; sum <= n; j++) {
      sum = sum + j; 
      if (sum == n) {
        count++;
        break;
      }
    }
  }
  return count;
}

int main()
{
    int n;cin>>n;
    cout <<isSumOfConsecutive(n)<< endl;
    return 0;
}


