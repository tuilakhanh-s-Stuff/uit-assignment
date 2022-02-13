/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

#define MAXR 100
#define MAXC 100

int pow(int n)
{
    if (n%2==0)
        return 1;
    return -1; 
}

// Ma trận con
void newMatrix(int a[][MAXR], int b[][MAXR], int x, int y, int n)
{  
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            b[i][j] = a[i][j];
    for (i = x; i < n; i++)
        for (j = 1; j <= n; j++)
            b[i][j] = b[i+1][j];
    for (j = y; j < n; j++)
        for (i = 1; i <n; i++)
            b[i][j] = b[i][j+1];        
}

// tính định thức
long TinhDinhThuc(int a[][MAXR], int n)
{
	// Tinh dinh thuc cua a
	int i,j,k, sign = 1;
	long det = 1, temp;
  for (i = 0; i < n-1; i++)
  {
    if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì tìm hàng khác để đổi
    {
      k = i+1;
    	while (k < n && a[k][i] == 0) k++;
      if (k==n) 
			{ 
				return 0;
			} // Không timg thấy, tức det(a) = 0
      for (j = i; j < n; j++)// Đổi hàng i với hàng k
      {
        temp = a[i][j];
        a[i][j] = a[k][j];
      	a[k][j] = temp;
      }
      sign = -sign; // Định thức đổi dấu đó
    }
    for (j = i+1; j < n; j++)// Biển đổi để các phần tử cùng cột ở hàng dưới bằng 0 đó
    {
      temp = - static_cast<double>(a[j][i])/a[i][i];
      for (k = i+1; k < n; k++)   
				a[j][k] += temp*a[i][k]; // Nhân hàng i với (-a[j][i]/a[i][i]) rồi cộng vào hàng j
    }
    det *= a[i][i]; // Tính dần det(a)
  }
	det *= a[n-1][n-1];
	return det;
}
 
void NhapMaTran(int a[MAXR][MAXC], int &n)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> a[i][j];
}

int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout << TinhDinhThuc(a, n);
    return 0;
}
