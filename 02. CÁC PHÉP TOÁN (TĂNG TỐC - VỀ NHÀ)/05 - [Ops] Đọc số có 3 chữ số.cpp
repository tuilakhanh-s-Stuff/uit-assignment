#include <iostream>

int main() {

  int N, First, Second, Last;
  std::cin >> N;

  First = N / 100;
  Second = (N / 10) % 10;
  Last = N % 10;

  std::cout << "Chu so thuoc hang don vi: " << Last << '\n';
  std::cout << "Chu so thuoc hang chuc: " << Second << '\n';
  std::cout << "Chu so thuoc hang tram: " << First;

}
