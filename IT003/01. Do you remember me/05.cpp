#include <iostream>

using namespace std;

void shellSort(int *a, int n) 
{
  int temp = 0, j = 0;
  for (int gap = n/2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      temp = a[i];
      for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
        a[j] = a[j - gap];
      }
      a[j] = temp;
    }
  }
}

int counta(int *a, int n)
{
    int max_count = 1, num = a[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1])
            curr_count++;
        else {
            if (curr_count >= max_count) {
                max_count = curr_count;
                num = a[i - 1];
            }
            curr_count = 1;
        }
    }
    if (curr_count >= max_count)
    {
        max_count = curr_count;
        num = a[n - 1];
    }
 
    return num;
}

int countb(int *a, int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0])
            count++;
    }
    return n - count;
}

int main()
{
    int *a;
    int n;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    shellSort(a, n);
    cout << counta(a, n);
    return 0;
}
