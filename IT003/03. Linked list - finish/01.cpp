/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
using
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
//Hàm này đã viết chuẩn như ông Duẩn, sinh viên không cần viết
}

void xuat(List &l){
//Hàm này cũng đã được viết rất chuẩn, sinh viên không cần quan tâm
}


//###INSERT CODE HERE -
int length(List l)
{
	int count = 0;
	for (Node* it = l.head; it != NULL; it = it->next)
		count++;
	
	return count;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l;

    list_initializing(l);
    int x;
    do{
        cin >> x;
        if (x != -1) add_tail(l, x);
        else break;
    } while(true);

    cout << length(l);

    return 0;
}
