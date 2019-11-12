#include <iostream>
using namespace std;

class Base1 {
private:
	int data = 1;
public:
	Base1() {cout << "construct B1" << endl;};
	~Base1() {cout << "destroy B1" << endl;};
	virtual void printData() {cout << data << endl;};
};

class Derived1 : public Base1 {
private:
	int data = 2;
public:
	Derived1() {cout << "construct D1" << endl;}
	~Derived1() {cout << "destroy D1" << endl;}
	virtual void printData() override;
};

void Derived1::printData() {
	cout << data << endl;
}

class Derived2 : public Derived1 {
private:
	int data = 3;
public:
	Derived2() {cout << "construct D2" << endl;}
	~Derived2() {cout << "destroy D2" << endl;}
	virtual void printData() override;
};

void Derived2::printData() {
	cout << data << endl;
}

int main() {
	Derived2 d;
	Derived1 d1;
	Base1 b1;

	Derived1 *d1_2 = &d;
	Base1 *b1_2 = &d;

	// Derived2 *d2_1 = &d1; // should fail
	Base1 *b1_1 = &d1;

	// Derived2 *d2_b = &b1; // should fail
	// Derived1 *d1_b = &b1; // should fail

	d.printData();
	d1_2->printData();
	b1_2->printData();

	d1.printData();
	b1_1->printData();

	b1.printData();

	return 0;
}




