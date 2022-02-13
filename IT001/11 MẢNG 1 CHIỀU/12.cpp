#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

int secondLargest(int a[], int n)
{
  int first = -1, second = -1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > first)
    {
      second = first;
      first = a[i];
    }
    else if (a[i] > second && a[i] != first)
      second = a[i];
  }
  if (second == -1)
    return 0;
  else
    return second;
}

int main()
{
  int a[100000], n;
  inputArray(a, n);
  std::cout << secondLargest(a, n);
  return 0;
}
