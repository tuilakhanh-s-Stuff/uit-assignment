#include <iostream>

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

int checkArray(int a[], int n)
{
  int increase = 0, decrease = 0;
  for (int i = 0; i < n-1; i++)
  {
    if (a[i] < a[i+1])
      increase++;
    else if (a[i] > a[i+1])
      decrease++;
    /* else if (a[i] == a[i+1]) */
    /* { */
    /*   increase++; */
    /*   decrease++; */
    /* } */
  }
  if (n == 1)
    return 0;
  if (increase == n-1)
    return 0;
  else if (decrease == n-1)
    return 1;
  else
    return 2;
}

int main()
{
  int a[101], n;
  inputArray(a, n);
  int check = checkArray(a, n);
  switch(check)
  {
    case 0:
      std::cout << "Mang tang dan";
      break;
    case 1:
      std::cout << "Mang giam dan";
      break;
    case 2:
      std::cout << "Mang khong tang, khong giam";
      break;
  }
  return 0;
}
