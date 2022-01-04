#include <iostream>
#include <cstring>

void swapLowerUpper(char a[])
{
  for (int i = 0; i < strlen(a); i++)
  {
    if ('a' <= a[i] && a[i] <= 'z')
      a[i] = a[i] - 32;
    else if ('A' <= a[i] && a[i] <= 'Z')
      a[i] = a[i] + 32;
  }
}

int main()
{
  char a[10000];
  std::cin.getline(a, 10000);
  swapLowerUpper(a);
  std::cout << a;
  return 0;
}
