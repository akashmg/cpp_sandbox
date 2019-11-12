#include <iostream>
#include <vector>

using namespace std;

struct Bnode {
	uint16_t val;
	Bnode *left;
	Bnode *right;
};

Bnode* newNode(uint16_t val) {
	Bnode* n = new Bnode();
	n->val = val;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

Bnode* makeTree(vector<uint16_t>& a, int16_t start, int16_t end) {
	Bnode *n = nullptr;
	if (start > end)
		return nullptr;

	int16_t mid = (start + end)/2;
	n = newNode(a[mid]);
	n->left = makeTree(a, start, mid-1);
	n->right = makeTree(a, mid+1, end);

	return n;
}

Bnode* addNode(Bnode* n, uint16_t val) {
	if (n == nullptr) {
		n = newNode(val);
		return n;
	}
	if (val > n->val) {
		n->right = addNode(n->right, val);
	} else {
		n->left = addNode(n->left, val);
	}

	return n;
}

Bnode *minValueNode(Bnode* n) {
	while (n != nullptr && n->left != nullptr) {
		n = n->left;
	}

	return n;
}

Bnode* removeNode(Bnode* n, uint16_t val) {
	if (n == nullptr)
		return n;

	if (val < n->val) {
		n->left = removeNode(n->left, val);
	} else if (val > n->val) {
		n->right = removeNode(n->right, val);
	} else {
		if (n->left == nullptr) {
			Bnode *temp = n->right;
			delete n;
			n = nullptr;
			return temp;
		}
		if (n->right == nullptr) {
			Bnode *temp = n->left;
			delete n;
			n = nullptr;
			return temp;
		}

		Bnode* temp = minValueNode(n->right);
		n->val = temp->val;
		n->right = removeNode(n->right, temp->val);
		return n;
	}
}

void printTree(Bnode* n) {
	if (n == nullptr) {
		return;
	}
	printTree(n->left);
	cout << n->val << endl;
	printTree(n->right);
}


int main() {
	vector<uint16_t> a1 = {0,1,2,3,4};
	Bnode *b1 = makeTree(a1, 0, a1.size()-1);
	addNode(b1, 6);
	addNode(b1, 5);
	removeNode(b1, 6);
	printTree(b1);

	return 0;
}