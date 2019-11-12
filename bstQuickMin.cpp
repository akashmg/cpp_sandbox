#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Bnode {
	uint16_t l_ind;
	uint16_t r_ind;
	uint16_t m_ind;
	int16_t min;
	Bnode *left;
	Bnode *right;
};

int16_t min(int16_t a, int16_t b) {
	return a < b ? a : b;
}

Bnode* makeTree(vector<uint16_t>& a, int16_t start, int16_t end) {
	// Terminate if we have only one item
	if (start >= end)
		return nullptr;

	// Create a new node and assign index range
	Bnode* n = new Bnode;
	n->l_ind = start;
	n->r_ind = end;
	int16_t mid = (start + end)/2;
	n->m_ind = mid;
	// cout << start << " " << mid << " " << end << endl;
	if (start == end) {
		n->left = nullptr;
		n->right = nullptr;
		n->min = min(a[start], a[end]);
	} else {
		n->left = makeTree(a, start, mid);
		n->right = makeTree(a, mid+1, end);
		if (n->left == nullptr) {
			n->min = a[start];
		} else if (n->right == nullptr) {
			n->min = a[end];
		} else {
			n->min = min(n->left->min, n->right->min);
		}
	}

	return n;
}

void printTreeOrder(Bnode* n) {
	queue<Bnode *> t;
	t.push(n);
	while (t.size()) {
		// cout << t.size() << endl;
		Bnode *p = t.front();
		// cout << t[0]->l_ind << t[1]->r_ind << endl;
		if (p != nullptr) {
			cout << p->l_ind << p->min << p->r_ind << " ";
			t.push(p->left);
			t.push(p->right);
		}
		t.pop();
	}
}

void printTree(Bnode* n) {
	if (n == nullptr) {
		return;
	}
	cout << n->l_ind << n->r_ind << endl;
	printTree(n->left);
	printTree(n->right);
}

int16_t findMin(Bnode *n, uint16_t i, uint16_t j) {
	if (n == nullptr) {
		cout << "error" << endl;
		return -1;
	}
	if ((i >= j) || (i == n->l_ind && j == n->r_ind)) {
		return n->min;
	}

	if (i > n->m_ind) {
		return findMin(n->right, i, j);
	} else if (j <= n->m_ind) {
		return findMin(n->left, i, j);
	} else {
		return min(findMin(n->left, i, n->m_ind), findMin(n->right, n->m_ind+1, j));
	}
}


int main() {
	vector<uint16_t> a1 = {5,0,2,1,7,9,6};
	Bnode *b1 = makeTree(a1, 0, a1.size()-1);
	// printTreeOrder(b1);
	cout << findMin(b1, 1, 2) << endl;
	#error find min does not work

	return 0;
}