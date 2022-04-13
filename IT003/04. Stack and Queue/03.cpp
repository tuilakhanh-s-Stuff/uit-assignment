#include <iostream>

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

void push(List &l, int b)
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

bool isEmpty(List l)
{
	return l.head == NULL;
}

void peek(List l)
{
	if (isEmpty(l))
		std::cout << "EMPTY\n";
	else
		std::cout << l.head->value << '\n';
}

void pop(List &l, int b)
{
	peek(l);
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

int main()
{
	List l;
	l.head = NULL;
	l.tail = NULL;
	   
	std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

	int choose, n;
	do {
		std::cin >> choose;
		switch (choose) {
			case 1:
				std::cin >> n;
				push(l, n);
				break;
			case 2:
				pop(l, n);
				break;
			case 3:
				peek(l);
				break;
		}
	} while (choose != 4);

	return 0;
}
