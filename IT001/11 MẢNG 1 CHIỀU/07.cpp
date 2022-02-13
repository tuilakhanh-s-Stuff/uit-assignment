/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -

void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

bool palindrome(int a[], int n)
{
  for (int i = 0; i < n / 2 && n != 0; i++)
  {
    if (a[i] != a[n - i - 1])
      return false;
  }
  return true;
}

int main()
{
  int a[10000], n;
  inputArray(a, n);
  if (palindrome(a, n))
    std::cout << "array is palindrome";
  else
    std::cout << "array is not palindrome";
  return 0;
}
