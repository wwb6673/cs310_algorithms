// perform a divide-and-conquer gcd algorithm
// for problem set 1011
// implemented by William Briggs

#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

// the divide-and-conquer algorithm
// @param a one of the values to find the gcd of
// @param b the other value to find the gcd of
// @return the gcd of a and b
ulong get_gcd(ulong a, ulong b);

int main( int argc, char* argv[] )
{
  if( argc != 3 )
  {
    cerr << "Usage: " << argv[0] << " a b" << endl;
    cerr << "  where a and b are two unsigned ints to find the gcd of" << endl;
    cerr << "  both a and b non-negative" << endl;
    return 1;
  }

  ulong a {stoul( argv[1] )};
  ulong b {stoul( argv[2] )};
  assert(a > 0 && b > 0);
  
  /*Check for correct ordering*/
  if( a > b )
  {
    ulong tmp {b};
    b = a;
    a = tmp;
  }
  
  ulong gcd {get_gcd(a, b)};
  cout << gcd << endl;
  return 0;
}

ulong get_gcd(ulong a, ulong b)
{
  if( a == b) 
  {
    return a;
  }
  else if( (a % 2 == 0) && (b % 2 == 0))
  {
    return 2 * get_gcd(a / 2, b / 2);
  }
  else if ((a % 2 != 0) && (b % 2 == 0)) 
  {
    return get_gcd(a, b / 2);
  }
  else if ((a % 2 != 0) && (b % 2 != 0) && (a > b)) 
  {
      return get_gcd((a - b) / 2, b);
  }
  else if ((a % 2 != 0) && (b % 2 != 0) && (a < b)) 
  {
      return get_gcd(a, (b - a) / 2);
  }
  else 
  {
    return a;
  }
}
