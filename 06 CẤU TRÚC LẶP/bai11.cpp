//This is a shit don't read or use for any reson. Thank you!
#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

int main() {

  int n, k, p, q;
  std::cin >> n >> k >> p >> q;

  int lapde = ceil((double)n / (double)k);

  std::vector<int> de;
  for (int i = 0; i < lapde; i++) {
    for (int j = 0; j < k; j++){
      de.push_back(j);
      if (de.size() == n)
        break;
    }
  }
  int vitria = p*q;
  double u, v;
  for (int i = vitria - 1; i > 1; i--) {
    if (de[i] == de[vitria]) {
      u = round((double)i / 2.0);
      if ((i % 2) == 0)
        v = 2;
      else
        v = 1;
      std::cout << u << ' ' << v;
      exit(0);
    }
  }

  for (int i = vitria + 1; i < n; i++) {
    if (de[i] == de[vitria]) {
      u = round((double)i / 2.0);
      if ((i % 2) == 0)
        v = 2;
      else
        v = 1;
      std::cout << u << ' ' << v;
      exit(0);
    }
  }

  std::cout << "-1 -1";

  return 0;
}
