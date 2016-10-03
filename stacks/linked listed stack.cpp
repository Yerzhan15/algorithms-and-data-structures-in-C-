#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
	int val;
	Node *link;
	Node(int val) : val(val) {};
	Node(int val, Node *link) : val(val), link(link) {};
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

int main() {

	Node *A = new Node(47);
	Node *B = new Node(15, A);

	Stack s1;

	for (int i = 0; i < 7; i++)
		s1.push(i * i);

	s1.print();

	cout << "yes";

	return 0;
}