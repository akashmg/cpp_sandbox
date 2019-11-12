#include <iostream>
#include <cstring>
using namespace std;

struct A {
	A() {cout << "constructor no args" << endl;}
	A(const A&&) {cout << "move constructor" << endl;}
	A(const A& other) = default;
	A(int x) : x1(x) {cout << "constructor" << endl;}
	~A() {cout << "destructor" << endl;}
	int x1;
	bool operator==(const A& rhs) {
		return x1 == rhs.x1;
	}
	void operator=(const A& rhs) {
		x1 = rhs.x1;
	}
};

int main() {

	char s[] = {"hellohello"};
	char* x = NULL;
	int n = 0;
	while (x = strchr(s+n, 'h')) {
		cout << *x << endl;
		n = x - s + 1;
	}
	return 0;
	struct A a1(5);
	if (a1 == 4) {
		cout << "Equal" << endl;
	} else {
		cout << "Unequal" << endl;
	}

	struct A a2;
	a2.x1 = 9;
	a1 = a2;
	cout << a1.x1 << " " << a2.x1 << endl;

	return 0;
}