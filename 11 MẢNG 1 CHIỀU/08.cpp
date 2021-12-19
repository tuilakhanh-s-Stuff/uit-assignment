#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

void shellSort(int a[], int n) 
{
  int temp = 0, j = 0;
  for (int gap = n/2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      temp = a[i];
      for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
        a[j] = a[j - gap];
      }
      a[j] = temp;
    }
  }
}

int numAdd(int a[], int n)
{
  shellSort(a, n);
  int dis = a[n-1] - a[0] + 1 - n;
  for (int i = 0; i < n-1; i++)
  {
    if (a[i] == a[i+1])
      dis++;
  }
  return dis;
}

int main()
{
  int a[21], n;
  inputArray(a, n);
  std::cout << numAdd(a, n);
  return 0;
}
