#include <iostream>

void inputMatrix(int a[][100], int &m, int &n) 
{
  std::cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++) 
    {
      std::cin >> a[i][j];
    }
  }
}

void sumOutput(int a[][100],int b[][100], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      std::cout << a[i][j] + b[i][j] << ' ';
    std::cout << '\n';
  }
}

int main() {
  int a[100][100], b[100][100];
  int ma, na, mb, nb;
  inputMatrix(a, ma, na);
  inputMatrix(a, mb, nb);
  sumOutput(a, b, ma, na);
  return 0;
}
