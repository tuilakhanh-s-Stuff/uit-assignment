#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

void outputOddPos(int a[], int n)
{
  for (int i = 1; i < n; i+=2)
    std::cout << a[i] << ' ';
}

int main()
{
  int a[100], n;
  inputArray(a, n);
  outputOddPos(a, n);
  return 0;
}
