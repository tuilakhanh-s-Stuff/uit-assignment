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
class node
{
	public:
		int value;
		node *next;
};

class list
{
	public:
		node *head;
		node *tail;
};

void initialize_list(list &a)
{
	a.head = NULL;
	a.tail = NULL;
}

void add_front(list &a, int b)
{
	node *temp = new node;	
	temp->value = b;
	if (a.head == NULL)
	{
		a.head = temp;
		a.tail = a.head;
	}
	else
	{
		temp->next = a.head;
		a.head = temp;
	}
}

void add_back(list &a, int b)
{
	node *temp = new node;
	temp->value = b;
	if (a.tail == NULL)
	{
		a.head = temp;
		a.tail = a.head;
	}
	else
	{
		a.tail->next = temp;
		temp->next = NULL;
		a.tail = temp;
	}
}

int main()
{
    list a;
    initialize_list(a);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int x, b, c;
    do {
        cin >> x;
        switch (x){
        case 0:
            cin >> b;
            add_front(a, b);
            break;
        case 1:
            cin >> b;
            add_back(a, b);
            break;
        }
    } while (x != 3);

    for (node* it = a.head; it ; it = it->next){
        cout << it->value << " ";
    }
    return 0;
}
