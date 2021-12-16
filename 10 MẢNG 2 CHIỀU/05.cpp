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

float sumDiagonal(float a[][100], int m, int n) {
  float sum = 0;
  for (int i = 0; i < m; i++)
  {
    sum += a[i][i];
  }
  return sum;
}

int main() {
  int m, n;
  float a[100][100];
  std::cin >> m >> n;
  inputMatrix(a, m, n);
  std::cout << sumDiagonal(a, m, n);
  return 0;
}
