#include <iostream>
#include <string>
#include <sstream>
#include "string.h"
#include <vector>

using namespace std;

int x (5); // constructor init
int y (10);
// int z {4} // uniform init support only for c++11
struct dummy1 {
	int test1;
	int test2;
};

struct dummy2 {
	char *text;
};

static const char* a1 = "hello";
static const char* b = "/goodbye";

int add(const int x, const int y=9) {
	return x+y;
}

template <class T>
T sum(T a, T b)
{
	cout << "template" << endl;
	T result;
	result = a + b;
	return result;
}

int sum(int a, int b) {
	cout << "int" << endl;
	return a + b;
}

void check_size(const char* str) {
	cout << str << endl;
	cout << "sizeof " << sizeof(str) << endl;
	cout << "strlen " << strlen(str) << endl;
}

int main()
{
	char s1[] = {"how is it going?"};
	check_size(s1);
	s1[6] = 0;
	check_size(s1);
	// memcpy(s1, s1+4, 12);
	// cout << s1 << endl;
	// return 0;
	// int num_arr[10] = {0};
	// for (uint i=0;i<10;i++) {
	// 	num_arr[i] = i;
	// }
	// memmove(&num_arr[0], &num_arr[5], (10-5)*sizeof(num_arr[0]));
	// memset(&num_arr[5], 0, (10-5)*sizeof(num_arr[0]));
	// for (uint i=0;i<10;i++) {
	// 	cout << num_arr[i] << endl;
	// }
	std::vector<int> v_int{{1,2,3,4,5}};
	// v_int.push_back(6);
	// v_int.clear();
	// v_int.resize(10, 1);
	for (auto i : v_int) {
		cout << i << endl;
	}

	cout << sum(4.5, 3.2) << endl;
	cout << sum(4, 2) << endl;

	return 0;

	// int x1,y;
	// x1 = 0;
	// y = 3;
	// cout << x1 << y << endl;

	// if (x1++ == 0) {
	// 	cout << x1 << "check before increment" << endl;
	// } else {
	// 	cout << x1 << "check after increment" << endl;
	// }

	// struct dummy1 s1 {5, 9};
	// struct dummy1 s2 = s1;
	// cout << s2.test1 << s2.test2 << endl;

	// std::string a;
	// a = a1;
	// char x[40];
	// sprintf(x, "str %s", a1);
	// cout << x << endl;
	// cout << add(5) << endl;
	// return 0;
	// char *c = (char *)memchr(a, 'l', 4);
	// cout << c << endl;
	// cout << "What's your name and how old are you? ";
	// int result = x*y;
	// string hello="Hello World!";
	// getline (cin, hello);
	// cout << hello << endl;
	// cout << "I'm a C++ program" << endl;
	// cout << "x*y=" << result << endl;
	// char myntcs[] = "some text";
	// string mystring = myntcs;  // convert c-string to string
	// cout << mystring << endl;          // printed as a library string
	// cout << mystring.c_str() << endl;  // printed as a c-string

	// struct dummy1 *test = new struct dummy1[5];
	// test[1].test1 = 19;
	// cout << test[1].test1 << endl;
	// (test + 1)->test1 = 10;
	// cout << test[1].test1 << endl;
	// int i;
	// for (i=0; i<=4; i++) {
	// 	cout << i << endl;

	// cout << b << endl;

	// delete[] test;

	// std::string path = "test/path";
	// std::string *copy = &path;
	// std::string copy2 = *copy;

	// cout << copy->c_str() << endl;
	// cout << path.c_str() << endl;
	// cout << copy2 << endl;

	// std::string s1 = "ad";
	// std::string s2 = "bc";
	// cout << s1+":"+s2 << endl;

	return 0;
}