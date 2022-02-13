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

void multiplyMatrix(float a[][100], float b[][100], float multiply[][100], int ia, int ib, int jb)
{
  for (int i = 0; i < ia; i++)
  {
    for (int j = 0; j < jb; j++)
    {
      multiply[i][j] = 0;
      for (int k = 0; k < ib; k++)
      {
        multiply[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main() 
{
  float a[100][100], b[100][100];
  int ia, ja, ib, jb;
  inputMatrix(a, ia, ja);
  inputMatrix(b, ib, jb);
  float multiply[100][100];
  multiplyMatrix(a, b, multiply, ia, ib, jb);
  outputMatrix(multiply, ia, jb);
  return 0;
}
