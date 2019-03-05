/**
 * William Briggs
 * 1/23/2019
 * Assignment_126
 * 
 * This program manipulates variables, pointers and
 * references to achieve the desired output
 */

#include <iostream>
using namespace std;

/**
 * a function to manipulate variables and pointers
 * param x an int value passed by value
 * param & y a reference to y
 */
void foo(int x, int & y);

int main()
{
  int a {2};
  int b {4};
  int * c = new int{6};
  int & d {*c};

  foo(a, b);

  (*c) = ((*c) * 2) * (d / 2);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << *c << endl;
  cout << "d: " << d << endl;

  delete c;
  
  return 0;
}

void foo(int x, int & y)
{
  int * z = new int{8};
  x = 0;
  ++y;
  --(*z);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << *z << endl;

  delete z;
}
