/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -

void inputArray(int a[], int &na, int b[], int &nb)
{
  std::cin >> na >> nb;
  for (int i = 0; i < na; i++)
  {
    std::cin >> a[i];
  }
  for (int i = 0; i < nb; i++)
  {
    std::cin >> b[i];
  }
}

void outputArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << a[i] << '\n';
  }
}

void connect(int a[], int na, int b[], int nb, int c[], int &nc)
{
  nc = 0;
  for (int i = 0; i < nb; i++) {
    c[nc] = b[i];
    nc++;
  }
  for (int i = na - 1; i >= 0; i--) {
    c[nc] = a[i];
    nc++;
  }
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

int main() 
{
  int na, nb, nc;
  int a[2000], b[2000], c[4000];
  inputArray(a, na, b, nb);
  connect(a, na, b, nb, c, nc);
  shellSort(c, nc);
  outputArray(c, nc);
}
