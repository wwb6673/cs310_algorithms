/**
 * @author William Briggs
 * @title Assignment 131
 *
 * 1/30/2019
 * This program generates an array of random numbers,
 * determined by input from the console. It then sorts the numbers
 * from smallest to largest. As well as outputting the input size
 * and the number of operations that the function foo performed.
**/
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/**
 * This function sorts an array given from input, and counts
 * operations also given by reference from the function call.
 * @param array an array of with a determined size
 * @param ops an integer for counting operations
 */
void foo(vector <unsigned> & array, int & ops);

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values in the array" << endl;
    return 1;
  }

  srand(static_cast<unsigned>(time(nullptr)));

  unsigned number_of_values {static_cast<unsigned>(atoi(argv[1]))};

  // put n random values into the array
  vector <unsigned> values;
  for (unsigned count {0}; count < number_of_values; count++)
  {
    values.push_back(static_cast<unsigned>(rand()));
  }

  // use cout to output the numbers in the array
  for (unsigned i = 0; i < values.size(); ++i)
  {
    cout << values[i] << " ";
  }
  cout << endl;

  // declare an operations counter
  int ops {0};

  foo(values, ops);

  // outputs to cerr, the size of input and the number of operations
  cerr << values.size() << " " << ops << endl;

  return 0;
}

void foo(vector <unsigned> & array, int & ops)
{
  size_t n {array.size()}; ++ops;
  for (size_t select_index {0}; select_index < n - 1; select_index++)
  {
    ops += 2;
    auto smallest_value {array.at(select_index)}; ++ops;
    auto smallest_index {select_index}; ++ops;

    // Nested For Loop to interate and compare numbers to one specific index
    for (auto compare_index {select_index + 1}; compare_index < n;
         compare_index++)
    {
    ops += 2;
      if (array.at(compare_index) < smallest_value)
      {
        ops += 2;
        smallest_value = array.at(compare_index);
        smallest_index = compare_index;
      }
      ++ops;
    }
    //Swaps the smallest index detected with the current indexed value
    ops += 3;
    swap(array.at(smallest_index), array.at(select_index));
  }
  ++ops;
}
