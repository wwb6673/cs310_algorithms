/**
   dfs.cpp 
   depth-first search
   Jon Beck
*/
#include <iostream>
#include <list>
#include <vector>
#include "graph.h"
using namespace std;

/**
 * the routine to start at node u and go as far as possible without cycling
 * @param g the adjacency lists graph
 * @param u the starting node
 * @param visited the global list of already-visited nodes
 */
void explore( const Graph & g, unsigned u, vector<bool> & visited );

/**
 * the dfs algorithm proper
 * @param g the graph to run dfs on
 */
void dfs( const Graph & g );

/**
 * previsit: for now, just report
 * @param v the vertex we are previsiting
 */
void previsit(unsigned v);

/**
 * postvisit: for now, just report
 * @param v the vertex we are postvisiting
 */
void postvisit(unsigned v);

/**
 * utility function to provide a global counter, incremented
 * each time the function is called
 * @return the string representation of an integer
 */
unsigned tick();

int main()
{
  // declare a graph and read its info from std input
  Graph g;
  g.read_graph();

  // just so we can see the contents of the graph
  g.dump();
  
  // run depth-first search
  dfs( g );
  return 0;
}

void explore( const Graph & g, unsigned v, vector<bool> & visited )
{
  // set this vertex as visited, and get its adjacency list
  visited.at(v) = true;

  previsit(v);
  
  list<unsigned> list_of_adjacent_vertices {g.get_list(v)};
  
  // go through its adjacency list, exploring each unvisited
  // node one by one
  for(auto vertex : list_of_adjacent_vertices)
  {
    if(!visited.at(vertex))
    {
      explore( g, vertex, visited );
    }
  }

  postvisit(v);
}

void dfs( const Graph & g )
{
  cout << "starting dfs" << endl;
  // declare a vector for visited
  vector<bool> visited(g.size(), false);

  unsigned connected_component {0};

  for( unsigned vertex {0}; vertex < g.size(); vertex++)
  {
    if(!visited.at(vertex))
    {
      if (vertex != 0)
      {
        cout << endl;
      }
      cout << "Connected component: " << connected_component++ << endl;
      explore( g, vertex, visited );
    }
  }
  cout << endl;
}

void previsit(unsigned v)
{
  cout << '+'<< int_to_char(v) << ' ' << to_string(tick()) << ' ';
}

void postvisit(unsigned v)
{
  cout << '-'<< int_to_char(v) << ' ' << to_string(tick()) << ' ';
}

unsigned tick()
{
  static unsigned clock {0};
  clock++;
  return clock;
}
