#ifndef GRAPH_BECK
#define GRAPH_BECK

#include <vector>
#include <list>
#include <iostream>
#include <sstream>

/**
 * two helper functions so we can convert to and from character labels
 */
unsigned char int_to_char(unsigned value);
unsigned char_to_int(unsigned char letter);


class Graph
{
 public:

  /**
    * Read in the adjacency lists structure from std input.
    * Each line must take the form
    * label vertex vertex vertex ...
    * where label is the current vertex, starting at 0 and
    * numbered consecutively. Each vertex is adjacent to label.
    * All values whitespace separated, all lines newline terminated.
    * In practice, the number of vertices is limited to 26, after which
    * we've run out of uppercase letters and the labels become the symbols
    * square brackets, backslash, caret, underscore, and backtick before
    * continuing on with the lowercase letters.
    * No error checking is done.
    */
  void read_graph()
  {
    // clear out the vector if there's anything in it
    if(g.size() != 0 )
    {
      g.resize(0);
    }

    // read in the n lists
    std::string line;
    while( getline(std::cin, line ))
    {
      // since we do no error checking, we assume label is the
      // correct next integer
      std::list<unsigned> list_of_adjacent_vertices;
      std::stringstream line_stream(line);
      unsigned char vertex;
      line_stream >> vertex; // throw away the label
      while (line_stream >> vertex)
      {
        list_of_adjacent_vertices.push_back(char_to_int(vertex));
      }
      g.push_back(list_of_adjacent_vertices);
    } // while ! eof
  } //read_graph


  /**
   * the number of nodes in the graph
   * @return the number of nodes in the graph
   */
  size_t size() const
  {
    return g.size();
  }

  /**
   * constant access to a list
   * @param label the node whose list we're asking for
   * @return a list of adjacency nodes
   */
  const std::list<unsigned> & get_list( unsigned label ) const
  {
    return g.at(label);
  }

  /**
   * just for debugging, dump the entire graph to screen
   */
  void dump()
  {
    unsigned vertex {0};
    for( auto thislist : g )
    {
      std::cout << '[' << int_to_char(vertex) << ']';
      for( auto adjacent_vertex : thislist )
      {
        std::cout << " -> " << int_to_char(adjacent_vertex);
      }
      std::cout << std::endl;
      vertex++;
    }
  }

 private:

  std::vector< std::list<unsigned >> g;
};

unsigned char int_to_char(unsigned value)
{
  return static_cast<unsigned char>('A' + value);
}

unsigned char_to_int(unsigned char letter)
{
  return static_cast<unsigned int>(letter - 'A');
}

#endif
