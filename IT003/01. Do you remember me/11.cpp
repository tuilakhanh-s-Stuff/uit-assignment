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
#include <map>
using namespace std;

map<int*, int> BOOK;


void check(int *A, int na, int ca, int l, int r){
    if (BOOK.size() > 1) cout << "WRONG";
    if (BOOK.begin()->second != ca) cout << "WRONG";
    if (na > ca || ca > 2*na) cout << "WRONG";
    for(int i = l ; i <= r; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
void cap_phat(int *&a, int size){
    int *x = new int[size];
    BOOK[x] = size;
    a = x;
}

void giai_phong(int *a){
    delete a;
    BOOK.erase(a);
}
//###INSERT CODE HERE -
void array_insert(int *&A, int &na, int &capacity_a, int x)
{
    if (capacity_a == 0)
        cap_phat(A, ++capacity_a);
    if (na == capacity_a)
    {
        capacity_a = na*2;
        int *temp;
        cap_phat(temp, capacity_a);
        for (int i = 0; i < na; i++)
            temp[i] = A[i];
        giai_phong(A);
        A = temp;
        // giai_phong(temp);
    }
    // A[na] = x;
    // na++;
    na++;
    A[na-1] = x;
}

int main(){
    int capacity_a;
    int na;
    int *A;

    capacity_a = 0;
    na = 0;

    int x;
    while(cin >> x){
        array_insert(A, na, capacity_a, x);
        int l, r; cin >> l >> r;
        check(A, na, capacity_a, l, r);
    }

    return 0;
}
