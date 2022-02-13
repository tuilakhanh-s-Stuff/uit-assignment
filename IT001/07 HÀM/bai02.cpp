/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
?
else
[
###End banned keyword*/

#include <iostream>

using namespace std;


int sumMany(int m);
int main()
{
    int n;
    cin>>n; //So luong cac so nguyen can nhap
    
//###INSERT CODE HERE -
    cout << sumMany(n);
}

int sumMany(int m) {
  
  int sum = 0, num;
  for (int i = 0; i < m; i++) {
    cin >> num;
    sum += num;
  }
  return sum;
}


