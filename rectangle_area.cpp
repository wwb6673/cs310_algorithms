// a program to exercise several functions
// William Briggs
// 1/16/19

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

/**
 * compute the area of a rectangle
 * @param length the length of the rectangle
 * @param width the width of the rectangle
 * @return the area of a length X width rectangle
 */
unsigned get_rectangle_area (unsigned length, unsigned width);

/**
 * get a random value between low and high
 * @param low the smallest random value
 * @param high the largest random value
 * @return a random value between low and high
 */
unsigned get_rand_in_range (unsigned low, unsigned high);

int main(int argc, char * argv[])
{
  const unsigned MAX_WIDTH {75};
  const unsigned MAX_LENGTH {500};

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      "n where n is the number of rectangles to generate" << endl;
    return 1;
  }

  srand(static_cast<unsigned>(time(nullptr)));

  cout << "This program displays the area of rectangles" << endl;
  cout << "The widths are between 1 and " << MAX_WIDTH
       << " and the lengths, 1 and " << MAX_LENGTH << endl << endl;

  unsigned number_of_rectangles {static_cast<unsigned>(atoi(argv[1]))};

  for (unsigned rectangle {0}; rectangle < number_of_rectangles; rectangle++)
  {
    unsigned length {get_rand_in_range(1, MAX_LENGTH)};
    unsigned width {get_rand_in_range(1, MAX_WIDTH)};
    unsigned area {get_rectangle_area(length, width)};

    cout << "The area of a " << width << "by" << length <<
      "rectangle is " << area << endl;
  }
  return 0;
}

unsigned get_rand_in_range (unsigned low, unsigned high)
{
  unsigned value {static_cast<unsigned>(rand()) % (high - low + 1) + low};
  return value;
}

unsigned get_rectangle_area (unsigned length, unsigned width)
{
  return length * width;
}
    
