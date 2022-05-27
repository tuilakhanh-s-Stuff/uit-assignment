#include <iostream>
using namespace std;

#define fast_io     ios_base::sync_with_stdio(false)

struct node
{
	int value;
    int count;
	node *pLeft, *pRight;
};

node* CreateNode(int x) {
    node* temp = new node;
    temp->value = x;
    temp->count = 1;
    temp->pLeft = temp->pRight = NULL;
    return temp;
}

void add_node(node*& root, int x)
{
    if (root == NULL) root = CreateNode(x);
    else if (root->value > x) add_node(root->pLeft, x);
    else if (root->value < x) add_node(root->pRight, x);
    else if (root->value == x) root->count += 1;
}

void rnl(node* root)
{
    if(root){
        rnl(root->pRight);
        cout << root->value << " " << root->count << "\n";
        rnl(root->pLeft);
    }
}

int main(){
 	cin.tie(NULL);
	fast_io;

    node* r = NULL;
    int x;
    while(true){
        cin >> x;
        if(x == 0) break;
        add_node(r, x);
    }
    rnl(r);

	return 0;
}
