/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct Node
{
	int value;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
};

void initialize_list(List &l)
{
	l.head = NULL;
	l.tail = NULL;
}

void addNodeHead(List &l, int b)
{
	Node *temp = new Node;	
	temp->value = b;
	if (l.head == NULL)
	{
		l.head = temp;
		l.tail = temp; 
	}
	else
	{
		temp->next = l.head;
		l.head = temp;
	}
}

void addNodeTail(List &l, int b)
{
	Node *temp = new Node;
	temp->value = b;
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

Node *findNode(List l, int n)
{
	for (Node *pos = l.head; pos != NULL; pos = pos->next)
		if (pos->value == n)
		{
			return pos;
		}
	return NULL;	
}

void addAfterNode(List &l, Node *pos, int n)
{
	Node *temp = new Node;
	temp->value = n;
	if (pos == NULL)
	{
		addNodeHead(l, n);
	}
	else if (pos == l.tail)
	{
		addNodeTail(l, n);
	}
	else
	{
		temp->next = pos->next;
		pos->next = temp;
	}
}

int main()
{
	cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

	List l;
    initialize_list(l);

    int x, n, m;
    do {
        cin >> x;
        switch (x){
        case 0:
            cin >> n;
            addNodeHead(l, n);
            break;
        case 1:
            cin >> n;
            addNodeTail(l, n);
            break;
        case 2:
            cin >> m >>  n;
			Node *pos = findNode(l, n);
			addAfterNode(l, pos, n);
            break;
        }
    } while (x != 3);

    for (Node* i = l.head; i ; i = i->next){
        cout << i->value << " ";
    }

	return 0;
}
