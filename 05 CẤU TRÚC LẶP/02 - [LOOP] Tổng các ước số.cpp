#include <iostream>

int main() {

  int n, total = 0, i;
  std::cin >> n;
  i = 1;
  while(i < n) {
    if (n % i == 0) {
      total += i;
    }
    i++;
  }
  std::cout << total;
  
}
