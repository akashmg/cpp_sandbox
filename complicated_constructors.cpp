#include <iostream>
#include <array>
using namespace std;


class B {
public:
	B(int x) {my_x = x; cout << " B const x= " << x << endl;}
private:
	int my_x;
};

template <int num>
class A {
public:
	A() : b_list({B(1), B(2), B(3), B(4), B(5)}){
	cout << "A constructor" << endl;
	};
private:
	std::array<B, num> b_list;
};

void test_fn() {
	static int count = 0;
	if (count == 0) {
		int x[5] = {1,1,1,1,1};
	} else if (count == 1) {
		int x[5] = {2,2,2,2,2};
	} else if (count == 2) {
		struct test {
			int x;
			int y;
		} t1 = {.x = 5};
		int y2;
		cout << t1.x << " " << t1.y << " " << y2 << endl;
	}
	count++;
}

int main() {

	A<5> a1;
	test_fn();
	test_fn();
	test_fn();
	return 0;
}