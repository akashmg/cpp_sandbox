#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int val;
	vector<Node *> child;
	Node(int val) {
		this->val = val;
	}
	~Node() = default;
};

void addNode(Node* root, int val) {
	Node* n = new Node(val);
	root->child.push_back(n);
}

void printTree(Node* root) {
	if (root == nullptr) {
		return;
	}
	queue<Node *> q;
	q.push(root);
	while (q.size()) {
		int n = q.size();
		while (n > 0) {
			Node* t = q.front();
			cout << t->val << " ";
			q.pop();
			for (const auto& it : t->child) {
				q.push(it);
			}
			n--;
		}
		cout << endl;
	}
}

int main() {
	cout << "General Trees" << endl;
	Node* n1 = new Node(0);
	addNode(n1, 1);
	addNode(n1, 2);
	addNode(n1, 3);
	addNode(n1->child[0], 4);
	addNode(n1->child[0], 5);
	addNode(n1->child[1], 6);
	addNode(n1->child[2], 7);
	addNode(n1->child[2], 8);
	addNode(n1->child[2], 9);
	printTree(n1);

	return 0;
}