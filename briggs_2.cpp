//William Briggs
//Assignment 1

#include <iostream>
#include <vector>
using namespace std;

void foo(uint x, uint & y);

int main()
{
  cout << "beginning of main" << endl;
  
  uint a {20};
  uint b {30};
  
  //creates a pointer 'c' to an object on the heap with value 40 stored
  uint * c = new uint(40);
  
  //creates a reference 'd' to an object on the heap
  uint & d {*c};
  
  //passes variable 'a' by value and 'b' by reference
  foo(a, b);
  
  //changes value of the object on the heap
  d = d * 5;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << *c << endl;
  cout << "d: " << d << endl;
  cout << "end of main" << endl;
  
  delete c; //deallocate memory
}

/**foo manipulates numbers and prints x, y, and z values
 * @param x : passes the value of x
 * @param y : passes a reference to y
 */
void foo(uint x, uint & y)
{
  cout << "beginning of foo" << endl;
  
  //creates uint object on heap and stores the value 50
  uint * z = new uint(50);
  
  //Mmnipulates number stored at 'x'
  x = x * 5;
  
  //'y' reference to variable 'b' outside the function and increments
  y += 2;
  
  //dereference pointer 'z' and increment number stored in that location
  --*z;
  
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << *z << endl;
  cout << "end of foo" << endl;
  
  delete z; //deallocate memory
}
