#include <iostream>

void inputMatrix(float a[][100], int &m, int &n) 
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

void sumOutput(float a[][100],float b[][100], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      std::cout << a[i][j] + b[i][j] << ' ';
    std::cout << '\n';
  }
}

int main() {
  float a[100][100], b[100][100];
  int ma, na, mb, nb;
  inputMatrix(a, ma, na);
  inputMatrix(b, mb, nb);
  sumOutput(a, b, ma, na);
  return 0;
}
