/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
  int value;
  Node *pLeft, *pRight;
};

Node* CreateNode(int x) {
  Node* temp = new Node;
  temp->value = x;
  temp->pLeft = temp->pRight = NULL;
  return temp;
}

void add_node(Node*& root, int x) {
  if (root == NULL)
    root = CreateNode(x);
  else if (root->value > x)
    add_node(root->pLeft, x);
  else if (root->value < x)
    add_node(root->pRight, x);
}

int maxDepth(Node* root) {
  if (root == NULL)
    return -1;
  else {
    int lDepth = maxDepth(root->pLeft);
    int rDepth = maxDepth(root->pRight);

    if (lDepth > rDepth) return lDepth + 1;
    return rDepth + 1;
  }
}

int main() {
  cin.tie(NULL);

  Node* root = NULL;
  int x;
  while (true) {
    cin >> x;
    if (x == 0) break;
    add_node(root, x);
  }
  cout << maxDepth(root) + 1;
  return 0;
}
