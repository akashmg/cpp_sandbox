#include <iostream>

using namespace std;

class A {
public:
	void name() {cout << "A" << endl;};
	A(){};
	~A(){};
};

class B {
public:
	void name() {cout << "B" << endl;};
	B(){};
	~B(){};
};

class C : public A, public B {
public:
	C(){};
	~C(){};
};

int main(int argc, char const *argv[]) {
	C c1;

	A* a1 = (A*)c1;
	a1->name();

	return 0;
}