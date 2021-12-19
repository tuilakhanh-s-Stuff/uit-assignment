#include <iostream>
#include <math.h>
#include <iomanip>

void inputArray(double a[], double &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

double meanArray(double a[], double n)
{
  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  return sum / n;
}

double standardDeviation(double a[], double n, double mean)
{
  double variance = 0;
  for (int i = 0; i < n; i++)
  {
    variance += std::pow(a[i] - mean, 2);
  }
  return std::sqrt(variance / n);
}

int main()
{
  double a[10000];
  double mean, dev;
  double n;
  inputArray(a, n);
  mean = meanArray(a, n);
  dev = standardDeviation(a, n, mean);
  std::cout << std::setprecision(10) << dev;
  return 0;
}
