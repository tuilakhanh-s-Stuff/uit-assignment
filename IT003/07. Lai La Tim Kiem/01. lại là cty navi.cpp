/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node {
  int ms;
  node *pLeft, *pRight;
};

node* CreateNode(int x) {
  node* temp = new node;
  temp->ms = x;
  temp->pLeft = temp->pRight = NULL;
  return temp;
}

void add_node(node*& root, int x) {
  if (root == NULL) root = CreateNode(x);
  else if (root->ms > x) add_node(root->pLeft, x);
  else if (root->ms < x) add_node(root->pRight, x);
}

node* find(node* root, int x) {
  if (root == NULL)
    return NULL;
  else if (root->ms == x)
    return root;

  if (root->ms > x) 
	return find(root->pLeft, x);
  return find(root->pRight, x);
}

int main() {
  cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  node* a = NULL;
  int x, ms;
  do {
    cin >> x;
    if (x == 0) break;
    cin >> ms;
    if (x == 1)
      add_node(a, ms);
    else if (x == 2)
      cout << (find(a, ms) == NULL ? 0 : 1) << "\n";
  } while (x > 0);
  // output(a);
}
