#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Node {
	char val;
	Node *link;
	Node(char val) : val(val) {};
	Node(char val, Node *link) : val(val), link(link) {};
};

class Stack {
	private: 
		Node *top;
		int size;

	public:
		Stack(); // constructor

		void push(int val) {
			Node *node = new Node(val, top);
			top = node;
		}

		char pop() {
			char c = top -> val;
			delete top; // freed memory
			top = top -> link;
			return c;
		}

		void print() {
			Node *cur = top;
			while (cur != NULL) {
				cout << cur -> val << " ";;
				cur = cur -> link;
			}
			cout << endl;
		}
};

Stack::Stack(void) {
	top = NULL;
	size = 0;
}

string reverse_string(string s) {
	Stack stack;
	for (int i = 0; i < s.length(); i++)
		stack.push(s[i]);

	string rs = "";
	for (int i = 0; i < s.length(); i++)
		rs += stack.pop();

	return rs;
}

int main() {

	cout << reverse_string("Kazakhstan");

	return 0;
}