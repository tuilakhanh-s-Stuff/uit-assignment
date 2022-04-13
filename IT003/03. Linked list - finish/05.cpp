/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

//###INSERT CODE HERE -
void add_tail(List &l, int b)
{
	Node *temp = new Node;
	temp->val = b;
	if (l.tail == NULL)
	{
		l.head = temp;
		l.tail = l.head;
	}
	else
	{
		l.tail->next = temp;
		temp->next = NULL;
		l.tail = temp;
	}
}

void copy(List l1, List &l2)
{
	Node *current = new Node;
	current->val = l1.head->val;

	l2.head = current;
	Node *prev = current;

	l1.head = l1.head->next;

	while (l1.head != NULL)
	{
		current = new Node;
		current->val = l1.head->val;
		prev->next = current;
		prev = prev->next;
		l1.head = l1.head->next;
	}
	l2.tail = current;
	current->next = NULL;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
