#include <iostream>
#include <string>

struct Node
{
	char value;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
}; 

void push(List &l, int b)
{
	Node *temp = new Node;	
	temp->value = b;
	if (l.head == NULL)
	{
		l.head = temp;
		l.tail = l.head;
	}
	else
	{
		temp->next = l.head;
		l.head = temp;
	}
}

bool isEmpty(List l)
{
	return l.head == NULL;
}

char peek(List l)
{
	return l.head->value;
}

void pop(List &l)
{
	if (l.head == NULL)
	{
		return;
	}
	else if (l.head == l.tail)
	{
		delete l.head;
		l.head = NULL;
		l.tail = l.head;
	}
	else
	{
		Node *temp = l.head;
		l.head = l.head->next;
		delete temp;
	}

}


bool checkParenthesis(std::string s)
{
	char dict[10000];
	dict[')'] = '(';
	dict[']'] = '[';
	dict['}'] = '{';

	List l;
	l.head = NULL;
	l.tail = NULL;

	std::string dictOpen = "([{";
	for (int i = 0; i < s.length(); i++) {
		if (dictOpen.find_last_of(s[i]) != std::string::npos) {
			push(l, s[i]);
		}
		else {
			if (isEmpty(l)) {
				return false;
			} else if (peek(l) != dict[s[i]]) {
				return false;	
			} else {
				pop(l);
			}
		}
	}

	if (isEmpty(l))
		return true;
	return false;
}

int main()
{
	std::string s;
	do {
		std::cin >> s;
		if (s == "END")
			break;
		std::cout << (checkParenthesis(s) ? "TRUE" : "FALSE") << '\n';
	} while(true);

	return 0;
}
