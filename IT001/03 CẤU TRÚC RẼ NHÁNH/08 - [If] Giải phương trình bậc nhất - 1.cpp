#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin>>a>>b;

  if (a == 0) {
    if (b == 0) {
      cout<<"VSN";
    } else {
      cout<<"VN";
    }
  } else {
    cout<<"x = "<<(double)-b/a;
  }
  return 0;
}
