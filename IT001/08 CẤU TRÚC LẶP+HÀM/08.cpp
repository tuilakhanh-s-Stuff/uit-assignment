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

long long primeFactor (int n) {
  long long factor = 1;
  std::vector<bool> primes = primesVector(n); 
  for (int i = 2; i < primes.size(); i++){
    if (primes[i]) {
      factor = factor * i;
    }
  }
  return factor;
}

int main() {
  
  int n;
  std::cin >> n;

  std::cout << primeFactor(n);

  return 0;
}
