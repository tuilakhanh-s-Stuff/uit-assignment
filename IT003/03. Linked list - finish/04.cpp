/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using  std::cin;
using  std::cout;
using  std::endl;
using std::ios_base;

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
		l.tail = l.head;
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
	for (Node *pos = l.head; pos; pos = pos->next)
		if (pos->value == n)
			return pos;
	return NULL;	
}

Node *findPrevNode(List l, int n)
{
	Node *pos = l.head;
	while (pos != NULL)
	{
		if (pos->next == NULL)
			return NULL;
		else if (pos->next->value == n)
			return pos;
		pos = pos->next;
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

void deleteHead(List &l)
{
	if (l.head == NULL)
	{
		return;
	}
	else if (l.head == l.tail)
	{
		delete l.head;
		l.head = NULL;
		l.tail = l.head;
	}
	else
	{
		Node *temp = l.head;
		l.head = l.head->next;
		delete temp;
	}
}

void deleteTail(List &l, Node *prev)
{
	if (l.tail == NULL)
	{
		return;
	}
	else if (l.head == l.tail)
	{
		delete l.tail;
		l.tail = NULL;
		l.head = l.tail;
	}
	else
	{
		delete l.tail;
		l.tail = prev;
		l.tail->next = NULL;
	}	
}

void deleteNode(List &l, Node *posPrev, int n)
{
	if (l.head == NULL)
		return;
	else if (l.head->value == n)
		deleteHead(l);
	else if (posPrev != NULL)
	{
		if (posPrev->next == l.tail)
		{
			deleteTail(l, posPrev);
		}
		else
		{
			Node *posNext = posPrev->next;
			posPrev->next = posNext->next;
			delete posNext;
		}
	}
}

void deleteAllNode(List &l, int n)
{
	if (l.head == NULL)
		return;
	else if (l.head->value == n)
		deleteHead(l);

	Node *pos = l.head;
	while (pos != NULL)
	{
		if (pos->next == NULL)
			break;
		else if (pos->next->value == n)
		{
			if (pos->next == l.tail)
			{
				deleteTail(l, pos);
			}
			else
			{
				Node *posNext = pos->next;
				pos->next = posNext->next;
				delete posNext;
			}
		}	
		else
			pos = pos->next;
	}
}

int main()
{
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

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
			addAfterNode(l, findNode(l, m), n);
            break;
		case 3:
			cin >> n;
			deleteNode(l, findPrevNode(l, n), n);
			break;
		case 4:
			cin >> n;
			deleteAllNode(l, n);
			break;
		case 5:
			deleteHead(l);
			break;
        }
    } while (x != 6);

    for (Node* i = l.head; i ; i = i->next){
        cout << i->value << " ";
    }

	return 0;
}
