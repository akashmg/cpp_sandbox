#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <typeinfo>

using namespace std;

struct a {
	int u;
	int type;
};

std::vector<struct a> v;
void fvp(std::vector<struct a>& vp) {
	struct a a2{2,2};
	vp.push_back(a2);
}

void add_int(int y) {
	y++;
	cout << y << endl;
}

int main() {
	// std::unordered_map<int*, std::unordered_map<int, int>> my_map;
	// int x = 1;
	// my_map[&x][1] = 3;
	// auto& map2 = my_map[&x];
	// cout << map2.size() << my_map.size() << endl;
	// for (auto it=map2.begin(); it!=map2.end(); it++) {
	// 	it->second = 0;
	// 	map2.erase(it);
	// 	cout << map2.size() << my_map.size() << endl;
	// }
	// my_map.erase(&x);
	// cout << map2.size() << my_map.size() << endl;

	// return 0;

	// std::unordered_map<int, a*> num_map{};
	// struct a amap{3, 5};

	// auto rty = num_map[1];
	// // rty = new a{9,2};
	// if (rty == nullptr) {
	// 	cout << "init null" << endl;
	// } else {
	// 	cout << rty->u << endl;
	// }
	// num_map[2] = &amap;
	// // if (num_map.find(2) != num_map.end()) {
	// // 	cout << num_map.begin()->first << num_map.begin()->second << endl;
	// // }

	// cout << &amap << &amap.u<< endl;
	// cout << &num_map[2] << &num_map[2]->u << endl;


	// return 1;

	// struct a a1{1,1};
	// v.push_back(a1);
	// fvp(v);
	// for (auto it=v.begin(); it!=v.end(); it++) {
	// 	cout << it->u << it->type << endl;
	// }

	// int& r = a1.u;
	// r = 93;
	// cout << a1.u << endl;

	std::bitset<3> my_bits;

	my_bits[1] = 1;
	if (my_bits[98] == 0)
		cout << my_bits << endl;
	if (my_bits[1])
		cout << "test works" << endl;
	std::string x = "bit1:" + std::to_string(my_bits[1]);

	// add_int(8);

	// int j=0;
	// if (++j) {
	// 	cout << "post" << endl;
	// }

	// std::array<int, 4> arr_1{1, 1, 1, 1};

	// float sum = 0;

	// std::for_each(arr_1.begin(), arr_1.end(),
	//               [&sum](int8_t dat) { sum += dat; });
	// cout << sum << endl;

	// if (!arr_1[3]--) {
	// 	cout << "decrement before not" << endl;
	// }
	// cout << arr_1[3] << endl;
	cout << "unorderd map test" << endl;
	std::unordered_map<int, int> um1 = {{1,1}, {2,2}, {3,3}, {4,4}};
	std::map<int, int> m1 = {{1,1}, {2,2}, {3,3}, {4,4}};

	for (auto it = um1.begin(); it != um1.end();) {
		cout << it->first << " ";
		// auto it2 = um1.find(it->first);
		it = um1.erase(it);
		cout << um1.size() << endl;
	}

	cout << "map test" << endl;
	for (auto it = m1.begin(); it != m1.end(); it++) {
		cout << it->first << " ";
		m1.erase(it);
		cout << m1.size() << endl;
	}
}