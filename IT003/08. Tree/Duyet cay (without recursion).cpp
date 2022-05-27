
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
};



void lnr(Node *t){
  Node *p = t;
  while (p != NULL) {
	if (p->left != NULL) {
	  Node *q = p->left;
	  while (q->right != NULL && q->right != p)
		q = q->right;
	  if (q->right == NULL) {
		q->right = p;
		p = p->left;
	  } else {
		q->right = NULL;
		cout << p->val << '\n';
		p = p->right;
	  }
	} else {
	  cout << p->val << '\n';
	  p = p->right;
	}
  }
}

int main()
{

    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL;

    while(true){
        int x; cin >> x;
        if (x == 0) break;
        add_node(root, x); //Hàm đã có theo đúng quy tắc cây nhị phân tìm kiếm
    }

    lnr(root);

    return 0;
}
