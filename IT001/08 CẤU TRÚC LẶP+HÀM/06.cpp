
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
ucln
%
###End banned keyword*/

#include <iostream>
using namespace std;

int ucln (int a, int b){

    //###INSERT CODE HERE -
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  if (a == 0 && b == 0)
    return -1;
  else if (a == 0 || b == 0)
    return a +b;
  while (a != b){
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

int main (){
	int n,m ;
	cin >> n >> m;
    if (ucln(n,m)==-1) 
      cout <<n<<" va "<<n<<" khong co UCLN";
    else 
      cout<<"UCLN cua "<<n<<" va "<<m<<" la "<<ucln(n,m);

	return 0;
}
