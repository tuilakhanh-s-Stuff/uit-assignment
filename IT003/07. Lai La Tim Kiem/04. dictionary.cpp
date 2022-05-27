#include <iostream>
#include <string>

#define fast_io

struct Node {
  std::string WEnglish, WStrange;
  Node *pLeft, *pRight;
};

Node* CreateNode(const std::string &a, std::string &b) {
  Node* temp = new Node;
  temp->WEnglish = a;
  temp->WStrange = b;
  temp->pLeft = temp->pRight = NULL;
  return temp;
}

void add_node(Node*& root, std::string &a, std::string &b) {
  if (root == NULL) root = CreateNode(a, b);
  if (root->WStrange > b)
    add_node(root->pLeft, a, b);
  else if (root->WStrange < b)
    add_node(root->pRight, a, b);
}

Node* find(Node* root, std::string &c) {
  if (root == NULL)
    return NULL;
  else if (c == root->WStrange)
    return root;

  if (root->WStrange > c) 
	return find(root->pLeft, c);
  return find(root->pRight, c);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fast_io;

	Node* root = NULL;
	std::string a, b, c;
	int m, n;
	std::cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
			std::cin >> a >> b;
		add_node(root, a, b);
	}
	for (int i = 0; i < m; i++)
	{
		std::cin >> c;
		Node *temp = find(root, c);
		std::cout << (temp == NULL ? "eh" : temp->WEnglish) << "\n";
	}
	return 0; 
}
