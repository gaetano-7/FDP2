#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle() : width(5), height(5) {}
  Rectangle(int x, int y) : width(x), height(y) {}
  void set_width (int);
  void set_height (int);
  int get_width() const {return width;}; 
  int get_height() const {return height;};

  int area(void) { return width * height; }
};

void Rectangle::set_width (int x) {width = x;}
}

void Rectangle::set_height (int y) {height = y;}



int main() {
  Rectangle obj (3, 4);
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
