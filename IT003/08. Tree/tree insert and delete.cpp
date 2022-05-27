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
  if (root == NULL)
    root = CreateNode(x);
  else if (root->ms > x)
    add_node(root->pLeft, x);
  else if (root->ms < x)
    add_node(root->pRight, x);
}

node* find(node* root, int x) {
  if (root == NULL)
    return NULL;
  else if (root->ms == x)
    return root;

  if (root->ms > x) return find(root->pLeft, x);
  return find(root->pRight, x);
}

node* findMin(node* root) {
  if (root == NULL)
	return NULL;
  else if (root->pLeft == NULL)
	return root;
  return findMin(root->pLeft);
}

void Delete(node*& root, int key) {
  if (root == NULL)
	return;
  else if (root->ms > key)
	Delete(root->pLeft, key);
  else if (root->ms < key)
	Delete(root->pRight, key);
  else {
	if (root->pLeft == NULL && root->pRight == NULL) {
	  delete root;
	  root = NULL;
	} else if (root->pLeft == NULL) {
	  node* temp = root;
	  root = root->pRight;
	  delete temp;
	} else if (root->pRight == NULL) {
	  node* temp = root;
	  root = root->pLeft;
	  delete temp;
	} else {
	  node* temp = findMin(root->pRight);
	  root->ms = temp->ms;
	  Delete(root->pRight, temp->ms);
	}
  }
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
    else if (x == 3)
      Delete(a, ms);
  } while (x > 0);
}
