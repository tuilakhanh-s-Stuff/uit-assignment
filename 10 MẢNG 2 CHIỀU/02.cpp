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

bool isSymmetric(float a[][100], int m, int n) {
  for (int i = 0; i < m; i++) 
  {
    for (int j = 0; j < n; j++)
    {
      if (a[i][j] != a[j][i])
        return false;
    }
  }
  return true;
}

int main()
{
  int m, n;
  float a[100][100];
  std::cin >> m >> n;
  inputMatrix(a, m, n);
  std::cout << (isSymmetric(a, m, n) ? "Yes" : "No");
  return 0;
}
