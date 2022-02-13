#include <iostream>
#include <vector>
#include <math.h>

std::vector<bool> primesVector(int n) {

  std::vector<bool> primes(n+1, true);
  primes[0] = false;
  primes[1] = false;
  int limit = sqrt(n);
  for (int i = 2; i <= limit; ++i) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    } 
  }

  return primes;
}

int main() {
  
  int n;
  std::cin >> n;

  std::vector<bool> primes = primesVector(n);

  std::cout << '\n';
  int count = 0;
  for (int i = 2; i < primes.size() - 2; i++) {
    if (primes[i] && primes[i + 2]) {
      std::cout << i << ", " << i+2 << '\n';
      count++;
    }
  }
  std::cout << "Tong: " << count << " cap so sinh doi < " << n;

  return 0;
}
