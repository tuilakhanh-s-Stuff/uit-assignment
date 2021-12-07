/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cmath>
using namespace std;


//###INSERT CODE HERE -
#include <vector>
#include <algorithm>

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

int sum_common_prime (int a, int b) {
  int sum = 0;
  int ucln = __gcd(a, b);
  vector<bool> primes = primesVector(ucln);
  for (int i = 2; i <= ucln; i++) {
    if (primes[i] && ucln % i == 0)
      sum += i;
  }
  if (sum == 0)
    sum = -1;
  return sum;
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << sum_common_prime(m, n);
}
