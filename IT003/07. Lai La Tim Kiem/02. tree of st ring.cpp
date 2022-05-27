/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

//###INSERT CODE HERE -
struct Node {
  char *key;
  Node *pLeft, *pRight;
};

int strcmp(char *s1, char *s2) {
  int i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  if (s1[i] == s2[i])
    return 0;
  return s1[i] < s2[i] ? -1 : 1;
}

void strcpy(char *s1, char *s2) {
  int i;
  for (i = 0; s2[i] != '\0'; i++)
    s1[i] = s2[i];
  s1[i] = '\0';
}

Node* CreateNode(char *x) {
  Node* temp = new Node;
  temp->key = new char[100];
  strcpy(temp->key, x);
  temp->pLeft = temp->pRight = NULL;
  return temp;
}

void add_node(Node*& root, char *x) {
  if (root == NULL) root = CreateNode(x);
  if (strcmp(root->key, x) == 1)
    add_node(root->pLeft, x);
  else if (strcmp(root->key, x) == -1)
    add_node(root->pRight, x);
}

Node* find(Node* root, char *x) {
  if (root == NULL)
    return NULL;
  else if (strcmp(root->key, x) == 0)
    return root;

  if (strcmp(root->key, x) == 1) 
	return find(root->pLeft, x);
  return find(root->pRight, x);
}

int main() {
  cin.tie(NULL);
  fast_io;

  Node* a = NULL;
  int x;
  char *key = new char[100];
  do {
    cin >> x;
    if (x == 0) break;
	cin.ignore();
    cin.get(key, 100);
    if (x == 1)
      add_node(a, key);
    else if (x == 2)
      cout << (find(a, key) == NULL ? 0 : 1) << "\n";
  } while (x > 0);
}
