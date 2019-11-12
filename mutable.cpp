
#include <iostream>
#include <string>

using namespace std;
struct vals {
	int a;
	string b;
	char c;
};

void print_vals(const struct vals &p_vals)
{
	cout << p_vals.a << endl;
	cout << p_vals.b << endl;
	cout << p_vals.c << endl;
}

void update_vals(const struct vals &p_vals)
{
	struct vals local_vals = p_vals;

	print_vals(local_vals);
	local_vals.a = 5;
	local_vals.b = "bye";
	local_vals.c = 6;
	print_vals(local_vals);
}

int main(int argc, char const *argv[])
{
	const struct vals vals1{4, "hi", 8};

	print_vals(vals1);
	update_vals(vals1);
	print_vals(vals1);


	return 0;
}