/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
int input() {
  int n;
  std::cin >> n;
  return n;
}

int input(int &n){
  std::cin >> n;
  return n;
}

int TongUocChung(int a, int b) {
  int min, sum = 0;
  if (a > b)
    min = b;
  else
    min = a;
  for (int i = 1; i <= min; i++){
    if (a % i == 0 && b % i == 0)
      sum += i;
  }
  return sum;
}

int main(){
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}
