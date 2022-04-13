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

void cap_phat(int *&a, int size){
    int *x = new int[size];
    BOOK[x] = size;
    a = x;
}

void giai_phong(int *a){
    delete a;
    BOOK.erase(a);
}

struct mang{
    int *arr;
    int na;
    int capacity_a;
};
void check(mang A, int l, int r){
    if (BOOK.size() > 1) cout << "WRONG";
    if (BOOK.begin()->second != A.capacity_a) cout << "WRONG";
    if (A.na > A.capacity_a || A.capacity_a > 2*A.na) cout << "WRONG";
    for(int i = l ; i <= r; i++){
        cout << A.arr[i] << " ";
    }
    cout << endl;
}
//###INSERT CODE HERE -
void khoi_tao(mang &A)
{
    A.na = 0;
    A.capacity_a = 0;
}

void array_insert(mang &A, int pos, int x)
{
	if (A.capacity_a == 0)
        cap_phat(A.arr, ++A.capacity_a);
    if (A.na == A.capacity_a)
    {
        A.capacity_a = A.na*2;
        int *temp;
        cap_phat(temp, A.capacity_a);
        for (int i = 0; i < A.na; i++)
            temp[i] = A.arr[i];
        giai_phong(A.arr);
        A.arr = temp;
    }
	for(int i = A.na; i > pos; i--)
		A.arr[i] = A.arr[i - 1];
	A.arr[pos] = x;
	A.na++;
}

void array_del(mang &A, int pos)
{
	// A.capacity_a--;
	int *temp;
	int j = 0;
	cap_phat(temp, A.capacity_a);
	for(int i = 0; i < A.na; i++)
	{
		if (i != pos)
			temp[j++] = A.arr[i];	
	}
	giai_phong(A.arr);
	A.arr = temp;
	A.na--;
}

int main(){
    mang A;
    khoi_tao(A);

    int op, i, x;
    while(cin >> op >> i ){
        if (op == 1){
            array_del(A, i);
        } else {
            cin >> x;
            array_insert(A, i, x);

        }
        int l, r; cin >> l >> r;
        check(A, l, r);
    }
}
