#include <iostream>

void inputMatrix(float a[][100], int m, int n) 
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++) 
    {
      std::cin >> a[i][j];
    }
  }
}

void outputMatrix(float a[][100], int m, int n) 
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++) 
    {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main()
{
  int m, n;
  float a[100][100];
  std::cin >> m >> n;
  inputMatrix(a, m, n);
  outputMatrix(a, m, n);
}
