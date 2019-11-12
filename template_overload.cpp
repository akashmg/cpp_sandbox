// function template
#include <iostream>
#include <vector>
using namespace std;

template <class T>
T sum (T a, T b)
{
  cout << "template" << endl;
  T result;
  result = a + b;
  return result;
}

int8_t sum(int8_t a, int8_t b)
{
  cout << "int8_t" << endl;
  int8_t result;
  result = a + b;
  return result;
}

int main () {
  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum<int>(i,j);
  h=sum<double>(f,g);
  int8_t x1 = 4, x2 = 5;
  int8_t x = sum(x1, x2);
  cout << k << '\n';
  cout << h << '\n';

  std::vector<int> v1(3);
  cout << v1[0] << v1[1] << v1[2] << endl;

  return 0;
}