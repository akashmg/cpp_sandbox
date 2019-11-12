// // example: one class, two objects
// #include <iostream>
// using namespace std;

// class Rectangle {
//     int width, height;
//   public:
//     void set_values (int,int);
//     int area () {return width*height;}
// };

// void Rectangle::set_values (int x, int y) {
//   width = x;
//   height = y;
// }

// int main () {
//   Rectangle rect, rectb;
//   rect.set_values (3,4);
//   rectb.set_values (5,6);
//   cout << "rect area: " << rect.area() << endl;
//   cout << "rectb area: " << rectb.area() << endl;
//   return 0;
// }

// // example: class constructor
// #include <iostream>
// using namespace std;

// class Rectangle {
//     int width, height;
//   public:
//     Rectangle (int,int);
//     int area () {return (width*height);}
// };

// Rectangle::Rectangle (int a, int b) {
//   width = a;
//   height = b;
// }

// int main () {
//   Rectangle rect (3,4);
//   Rectangle rectb (5,6);
//   cout << "rect area: " << rect.area() << endl;
//   cout << "rectb area: " << rectb.area() << endl;
//   return 0;
// }

// // overloading class constructors
// #include <iostream>
// using namespace std;

// class Rectangle {
//     int width, height;
//   public:
//     Rectangle ();
//     Rectangle (int,int);
//     int area (void) {return (width*height);}
// };

// Rectangle::Rectangle () {
//   width = 5;
//   height = 5;
// }

// Rectangle::Rectangle (int a, int b) {
//   width = a;
//   height = b;
// }

// int main () {
//   Rectangle rect (3,4);
//   Rectangle rectb;
//   cout << "rect area: " << rect.area() << endl;
//   cout << "rectb area: " << rectb.area() << endl;
//   return 0;
// }

// // classes and uniform initialization
// #include <iostream>
// using namespace std;

// class Circle {
//     double radius;
//   public:
//     Circle(double r) { radius = r; }
//     double circum() {return 2*radius*3.14159265;}
// };

// int main () {
//   Circle foo (10.0);   // functional form
//   Circle bar = 20.0;   // assignment init.
//   Circle baz {30.0};   // uniform init.
//   Circle qux = {40.0}; // POD-like

//   cout << "foo's circumference: " << qux.circum() << '\n';
//   return 0;
// }

// pointer to classes example
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {}
  ~Rectangle() {
  	cout << "destructor" << endl;
  }
  int area(void) { return width * height; }
};

void print_area(Rectangle& r) {
	cout << r.area() << endl;
}

int main() {
  Rectangle obj (3, 4);
  print_area(obj);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  delete bar;
  delete[] baz;
  return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main() {
//   char str1[] = "asdg\n23";
//   int n;
//   cout << strcspn(str1, "\n") << endl;
//   cout << str1[strcspn(str1, "\n")];
// }