#include <iostream>

void inputList(int array[], int &n) {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }
}

int even_odd_array (int array[], int n){
  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if ((array[i] % 2) == 0) {
      even++;
    } else {
      odd++;
    }
  }
  if (n == 0) {
    return 0;
  } else if (even == n) {
    return 1;
  } else if (odd == n) {
    return 2;
  } else
    return 3;
}

int main() {
  int n, a[101];
  inputList(a, n);
  switch(even_odd_array(a, n)) {
    case 0:
      std::cout << "Mang rong";
      break;
    case 1:
      std::cout << "Mang chua toan so chan";
      break;
    case 2:
      std::cout << "Mang chua toan so le";
      break;
    case 3:
      std::cout << "Mang khong chua toan so chan hay so le";
      break;
  }

  return 0;
}
