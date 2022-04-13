/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
cout
cin
printf
###End banned keyword*/

#include <iostream>
#include <algorithm>

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

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->val <= b->val) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

List merge_2_sorted_lists(List l1, List l2)
{
	List merge;

	merge.head = l1.head;
	Node *ref = l1.head;
	while (ref->next != NULL) {
		ref = ref->next;
	}
	ref->next = l2.head;
	merge.tail = l2.tail;

	MergeSort(&merge.head);
	// Node *current = merge.head;
	// Node *next = NULL;
	// int temp;

	// if (l2.head == NULL)
	// 	return l2;
	// else
	// {
	// 	while (current != NULL)
	// 	{
	// 		next = current->next;
	// 		
	// 		while (next != NULL)
	// 		{
	// 			if (current->val > next->val)
	// 			{
	// 				temp = current->val;
	// 				current->val = next->val;
	// 				next->val = temp;
	// 			}

	// 			next = next->next;
	// 		}

	// 		current = current->next;
	// 	}
	// }
	return merge;
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for(int i = 0; i < 2; i++){
        list_initializing(lists[i]);
        int x;
        do{
            cin >> x;
            if (x != 0) add_tail(lists[i], x);
            else break;
        } while(true);
    }

    List l = merge_2_sorted_lists(lists[0], lists[1]);

    xuat(l);

    return 0;
}
