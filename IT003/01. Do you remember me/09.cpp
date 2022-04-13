/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
delete
map
BOOK
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void array_insert(int A[], int &n, int pos, int x)
{
    int B[1000000];
    for (int i = 0; i < n; i++)
        B[i] = A[i];
    for (int i = pos; i < n; i++)
    {
        A[i + 1] = B[i];
    }
    A[pos] = x;
    n++;
}


void output(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
}

int main(){
    int A[1000000];
    int n = 0;
    int i, x;
    while(cin >> i >> x){
        array_insert(A, n, i, x);
    }
    output(A, n);
}
