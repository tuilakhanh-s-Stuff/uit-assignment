#include <iostream>
#include <vector>

void inputVector(std::vector<int>& a, int &n)
{
  std::cin >> n;
  int input;
  for (int i = 0; i < n; i++)
  {
    std::cin >> input;
    a.push_back(input);
  } 
}

void outputVector(const std::vector<int>& a)
{
  for (int i = 0; i < a.size(); i++)
    std::cout << a[i] << ' ';
}

void deleteElement(std::vector<int>& a)
{
  int left, right;
  std::cin >> left >> right;
  for (int i = left; i <= right; i++)
  {
    a.erase(a.begin() + left);
  }
}

int main()
{
  std::vector<int> a;
  int n;
  inputVector(a, n);
  deleteElement(a);
  outputVector(a);
  return 0;
}
