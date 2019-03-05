//Hash Function Assignment
//William Briggs

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

size_t hash_320( const string & key, size_t table_size );

size_t hash_bernstein( const string & key, size_t table_size );


/**
 * This program generates two different pseudo hash functions
 * and counts the numbers of collisions that each has. 
 */
int main()
{
  size_t size {99171};
  
  std::vector<bool> hash_check(size);
  long hash_320_collisions {0};
  
  std::vector<bool> bernstein_check(size);
  long bernstein_collisions {0};


  ifstream word_file;
  word_file.open("/usr/share/dict/words");

  string word;
  while( word_file >> word )
  {
    
    size_t hash_loc {hash_320(word, size)};
    if(hash_check[hash_loc] == 0)
    {
      hash_check[hash_loc] = 1;
    }
    else 
    {
      hash_320_collisions++;
    }
    
    hash_loc = hash_bernstein(word, size);
    if(bernstein_check[hash_loc] == 0)
    {
      bernstein_check[hash_loc] = 1;
    }
    else 
    {
      bernstein_collisions++;
    }

  }

  cout << "hash_320 Collisions: " << hash_320_collisions << endl;
  cout << "hash_bernstein Collisions: " << bernstein_collisions << endl;
  word_file.close();
  return 0;
}

/**Dr. Beck's Hash Function
 * Generates hash indeces based on input and table size
 * @param key : a const string reference to a word from file
 * @param table_size : the defined size of our "hash table"
 * @return hash_val % table_size : an index of our "hash table"
 */
size_t hash_320( const string & key, size_t table_size )
{
  size_t hash_val = 0;
  for( auto character : key )
  {
    hash_val = 37 * hash_val + static_cast< unsigned char >( character );
  }
  return hash_val % table_size;
}

/**Bernstein Hash Function
 * Source: http://www.cse.yorku.ca/~oz/hash.html
 * 
 * Generates hash indeces based on input and table size
 * @param key : a const string reference to a word from file
 * @param table_size : the defined size of our "hash table"
 * @return hash_val % table_size : an index of our "hash table"
 */
size_t hash_bernstein( const string & key, size_t table_size )
{
  size_t hash_val = 5381;
  for( auto character : key )
  {
    hash_val = (hash_val << 5) + hash_val 
      + static_cast< unsigned char >( character );
  }
  return hash_val % table_size;
}
