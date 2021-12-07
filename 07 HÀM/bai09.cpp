/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
bool soCP(int n) {
  int i = 0;
  while (i*i <= n) {
    if (i*i == n)
      return true;
    ++i;
  }
  return false;
}

int sum_all_square(int m) {
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    if (m % i == 0 && soCP(i))
        sum = sum + i;
  }
  if (sum == 0)
    return 1;
  else
    return sum;
}

int main() {
    int n;
    cin>>n;
    cout << sum_all_square(n);
}
