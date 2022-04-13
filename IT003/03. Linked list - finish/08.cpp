/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
new
delete
###End banned keyword*/

#include <iostream>
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
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}


bool is_palindrome(List &l){
	Node *slow = l.head;
	Node *fast = l.head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	Node *middle = slow;
	Node *current = middle;
  	Node *prev = NULL;
  	Node *next = NULL;
  	while (current != NULL) {
    	next = current->next;

   	 	current->next = prev;

    	prev = current;
    	current = next;
  	}
  	middle = prev;

	Node *head = l.head;
	while (middle != NULL)
	{
		if (middle->val != head->val)
			return false;
		head = head->next;
		middle = middle->next;
	}
	return true;
}

// void xuat(List &l){
//     for(Node *p = l.head; p != NULL; p = p->next){
//         cout << p->val << " ";
//     }
//     cout << endl;
// }

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l; list_initializing(l);

    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);

	// xuat(l);
    if (is_palindrome(l)) cout << "TRUE";
    else cout << "FALSE";
    cout << endl;

    return 0;
}
