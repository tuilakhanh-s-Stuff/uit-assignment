#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

void outputArray(int a[], int n)
{
  int x;
  std::cin >> x;
  for (int i = 0; i < n; i++)
    if (a[i] != x)
      std::cout << a[i] << ' ';
}

int main()
{
  int a[100000], n;
  inputArray(a, n);
  outputArray(a, n);
  return 0;
}
