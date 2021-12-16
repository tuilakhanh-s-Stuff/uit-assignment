
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
}

void outputArray(int a[], int n)
{
  for (int i = 0; i < n; i++) 
    std::cout << a[i] << ' ';
}

void insertElement(int a[], int &n, int pos, int x) {
  if (pos < 0 || pos >= n)
  {
    std::cout << "\nLoi: Vi tri khong hop le va se chen vao cuoi mang";
    a[n] = x;
    n++;
  } 
  else 
  {
    int b[100];
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    for (int i = pos; i < n; i++)
    {
      a[i + 1] = b[i];
    }
    a[pos] = x;
    n++;
  }
}

int main()
{
    int n, a[100],pos,x;
    inputArray(a,n);
    cin>>pos>>x;
    cout<<"Before: ";
    outputArray(a,n);

    insertElement(a,n,pos,x);

    cout<<"\nAfter: ";
    outputArray(a,n);

    return 0;
}
