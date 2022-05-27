#include <iostream>
using namespace std;

struct node {
  int ms;
  node *pLeft, *pRight;
};

class Queue {
 private:
  struct QNode {
    node *value;
    QNode *next;
  };
  QNode *head;
  QNode *tail;

 public:
  Queue() { head = tail = NULL; }

  ~Queue() {
    while (head) {
      QNode *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(node *value) {
    QNode *temp = new QNode;
    temp->value = value;
    temp->next = NULL;
    if (head == NULL)
      head = tail = temp;
    else {
      tail->next = temp;
      tail = temp;
    }
  }

  node *pop() {
    if (head == NULL) return NULL;
    node *value = head->value;
    QNode *temp = head;
    head = head->next;
    delete temp;
    if (head == NULL) tail = NULL;
    return value;
  }

  bool isEmpty() { return head == NULL; }
  node *front() { return head->value; }
  int size() {
    int count = 0;
    QNode *temp = head;
    while (temp) {
      count++;
      temp = temp->next;
    }
    return count;
  }
};

node *CreateNode(int x) {
  node *temp = new node;
  temp->ms = x;
  temp->pLeft = temp->pRight = NULL;
  return temp;
}

void add_node(node *&root, int x) {
  if (root == NULL)
    root = CreateNode(x);
  else if (root->ms > x)
    add_node(root->pLeft, x);
  else if (root->ms < x)
    add_node(root->pRight, x);
}

void BFS(node *root) {
  if (root == NULL) return;
  Queue q;
  q.push(root);
  while (!q.isEmpty()) {
    int node_count = q.size();
    while (node_count--) {
      node *temp = q.front();
      q.pop();
      cout << temp->ms << " ";
      if (temp->pLeft != NULL) q.push(temp->pLeft);
      if (temp->pRight != NULL) q.push(temp->pRight);
    }
	cout << '\n';
  }
}

int main() {
  cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  node *a = NULL;
  int x;
  do {
    cin >> x;
    if (x == 0) break;
    add_node(a, x);
  } while (true);
  BFS(a);
  return 0;
}
