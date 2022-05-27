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

node* find_lower_bound(node* root, int x) {
  if (root == NULL)
    return NULL;
  else if (root->ms == x)
    return root;
  else if (root->ms > x)
    return find_lower_bound(root->pLeft, x);
  else {
    node* temp = find_lower_bound(root->pRight, x);
    if (temp == NULL)
      return root;
    else
      return temp;
  }
}

node* find_upper_bound(node* root, int x) {
  if (root == NULL)
    return NULL;
  else if (root->ms == x)
    return root;
  else if (root->ms < x)
    return find_upper_bound(root->pRight, x);
  else {
    node* temp = find_upper_bound(root->pLeft, x);
    if (temp == NULL)
      return root;
    else
      return temp;
  }
}

int main() {
  cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  node* a = NULL;
  int x, ms;
  node* temp;
  do {
    cin >> x;
    if (x == 0) break;
    cin >> ms;
    if (x == 1)
      add_node(a, ms);
    else if (x == 2) {
      temp = find_lower_bound(a, ms);
      if (temp == NULL)
        cout << "NULL\n";
      else
        cout << temp->ms << '\n';
    } else if (x == 3) {
	  temp = find_upper_bound(a, ms);
      if (temp == NULL)
        cout << "NULL\n";
      else
        cout << temp->ms << '\n';
    }
  } while (x > 0);
}
