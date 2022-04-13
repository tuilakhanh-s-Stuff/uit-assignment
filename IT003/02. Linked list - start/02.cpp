/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;


//###INSERT CODE HERE -
void addBack(int *&A, int &na, int &capacity_a, int x)
{
    if (capacity_a == 0)
        A = new int[++capacity_a];
    if (na == capacity_a)
    {
        capacity_a = na*2;
        int *temp = new int[capacity_a];
        for (int i = 0; i < na; i++)
            temp[i] = A[i];
		delete A;
        A = temp;
    }
    na++;
    A[na-1] = x;
}

void addHead(int *&A, int &na, int &capacity_a, int x)
{
    if (capacity_a == 0)
        A = new int[++capacity_a];
    if (na == capacity_a)
    {
        capacity_a = na*2;
        int *temp = new int[capacity_a];
        for (int i = 0; i < na; i++)
            temp[i] = A[i];
		delete A;
        A = temp;
    }
 	for(int i = na; i > 0; i--)
		A[i] = A[i - 1];
	A[0] = x;
	na++;
}

int main()
{
	int capacity_a = 0;
	int na = 0;
	int *A;

    int b, x;
    do {
        cin >> b;
        switch (b){
        case 0:
            cin >> x;
            addHead(A, na, capacity_a, x);
            break;
        case 1:
            cin >> x;
        	addBack(A, na, capacity_a, x); 
            break;
        }
    } while (b != 3);
	
	for (int i = 0; i < na; i++)
		cout << A[i] << ' ';
	
	return 0;
}
