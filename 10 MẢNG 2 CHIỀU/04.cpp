/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

const int MAXR = 200;
const int MAXC = 200;

void NhapMaTran(int a[][MAXC], int &m) 
{
  std::cin >> m;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++) 
    {
      std::cin >> a[i][j];
    }
  }
}

bool isMaTranDonVi(int a[][MAXC], int m)
{
  /* if (m == 1 && a[0][0] != 1) */
  /*   return false; */
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++) 
    {
      if (i == j && a[i][i] != 1)
        return false;
      else if (i != j && a[i][j] != 0)
        return false;
    }
  }
  return true;
}

int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
