#include <iostream>
using namespace std;

int main() {
  int a, b;
  double x;
  cin>>a>>b;
  
  if (b >= 0)
    cout << "Phuong trinh " << a << "x+" << b << "=0 ";
  else
    cout << "Phuong trinh " << a << "x" << b << "=0 ";
  if (a == 0) {
    if (b == 0) {
      cout<< "co vo so nghiem";
    } else {
      cout<<"vo nghiem";
    }
  } else {
    x = (double)(-b)/(double)(a);
    cout<< "co 1 nghiem x = " << x;
  }
  return 0;
}
