//William Briggs
//Fibonacci sequence program

#include <iostream>
#include <vector>
using namespace std;

size_t fib1(size_t n);
int main(int argc, char * argv[])
{
  if(argc != 2)
  {
    cerr << "Usage: " << argv[0] << " n to find the nth Fibonacci number"
		 << endl;
	return 1;
  }
  size_t n = static_cast < size_t > (stoul(argv[1]));
  cout << "the " << n << "th Fibonacci number is " << fib1(n) << endl;
  return 0;
}

size_t fib1(size_t n)
{
  if(n == 0)
  {
    return 0;
  }
  if(n == 1)
  {
    return 1;
  }
  return fib1(n - 1) + fib1(n - 2);
}
