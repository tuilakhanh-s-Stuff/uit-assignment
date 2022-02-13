#include <iostream>

void inputArray(int a[], int b[], int &na, int &nb)
{
  std::cin >> na >> nb;
  for (int i = 0; i < na; i++)
    std::cin >> a[i];
  for (int i = 0; i < nb; i++)
    std::cin >> b[i];
}

void findMissingEle(int a[], int b[], int na, int nb)
{
  int j;
  for (int i = 0; i < na; i++)
  {
    for (j = 0; j < nb; j++)
      if (a[i] == b[j])
        break;
    if (j == nb)
      std::cout << a[i] << ' ';
  }
}

int main() 
{
  int a[1000], b[1000];
  int na, nb;
  inputArray(a, b, na, nb);
  findMissingEle(a, b, na, nb);
  return 0;
}
