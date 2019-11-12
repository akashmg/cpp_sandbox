#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <deque>

using namespace std;
std::string type;

void assign_string(std::string &name) {
	type = name;
}

int main() {
	std::deque<int> nums{1, 2};

	for (auto it = nums.begin(); it != nums.end();) {
		cout << "begin " << (int *)&nums[0] << " val " << nums[0] << endl;
		// if (*it % 2 == 0) {
			it = nums.erase(it);
		// } else {
		// 	it++;
		// }
	}
	cout << nums.size() << endl;
	return 0;

	auto it = std::find(nums.begin(), nums.end(), 2);
	if (it != nums.end()) {
		cout << "found" << endl;
	}

	std::string test = "test";
	assign_string(test);
	cout << type << &type << test << &test << endl;

	std::list<int> l1{};
	std::list<int> *l2;
	std::list<int> l3;

	l1.push_back(3);
	l1.push_back(26);
	l1.push_back(-4);
	l1.push_back(3);
	l1.push_back(-4);

	for (auto it=l1.begin(); it!=l1.end(); it++) {
		cout << *it << ' ' << endl;
	}

	// l2 = &l1;
	// l1.sort();
	// l3 = l1;
	// cout << "sorted" << endl;
	// for (auto it=l2->begin(); it!=l2->end(); it++) {
	// 	cout << *it << ' ' << endl;
	// }
	// cout << "l3" << endl;
	// for (auto it=l3.begin(); it!=l3.end(); it++) {
	// 	cout << *it << ' ' << endl;
	// }

	l2->unique();
	cout << "unique" << endl;
	for (auto it=l1.begin(); it!=l1.end(); it++) {
		cout << *it << ' ' << endl;
	}
	cout << "l3" << endl;
	for (auto it=l3.begin(); it!=l3.end(); it++) {
		cout << *it << ' ' << endl;
	}

	cout << l1.back() << endl;
	cout << l1.front() << endl;
}