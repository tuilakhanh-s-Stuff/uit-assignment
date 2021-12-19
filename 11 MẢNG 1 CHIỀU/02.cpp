#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

int largestElement(int a[], int n)
{
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

int countLargest(int a[], int n, int max)
{
  int count = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == max)
      count++;
  return count;
}

int main()
{
  int a[200], n;
  inputArray(a, n);
  int max, num;
  max = largestElement(a, n);
  num = countLargest(a, n, max);
  std::cout << max << '\n' << num;
  return 0;
}
