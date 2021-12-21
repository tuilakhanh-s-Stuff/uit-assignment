#include <iostream>
#include <math.h>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

void outputArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
    std::cout << a[i] << ' ';
}

void primeArray(bool primes[]) 
{
  int n = 101;
  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i < n; i++)
    primes[i] = true;
  int limit = sqrt(n);
  for (int i = 2; i <= limit; ++i)
  {
    if (primes[i]) 
      for (int j = i * i; j <= n; j += i) 
        primes[j] = false;
  }
}

int primeCheck(int a[], int p[], int n)
{
  bool primeArr[101];
  primeArray(primeArr);
  int counts = 0;
  for (int i = 0; i < n; i++)
  {
    if (primeArr(a[i]))
    {
      p[counts] = a[i];
      counts++;
    }
  }
  return counts;
}

int main()
{
  int a[60], p[60], n;
  inputArray(a, n);
  int counts = primeCheck(a, p, n);
  std::cout << counts << '\n';
  outputArray(p, counts);
  return 0;
}
