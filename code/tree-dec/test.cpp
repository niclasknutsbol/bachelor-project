#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using matrix = std::vector< std::set<unsigned> >;


//The (directed ) Graph is implemented as a adjacency list
struct Graph
{
   matrix vertex;
};

/*
 * Each row in the matrix "subset" in the class TreeDecomposition is a node in the tree
 * If the subset looks like:
 * 0 ->A,B
 * 1 ->A,D
 * 2 ->C,D
 * Means that we have three nodes in the graph were N_0 is (A,B) for exampel
 *
 * The matrix "tree" in the class TreeDecomposition stores the edges for the tree
 * The matrix tree looks like
 * 0 -> 1
 * 1 -> 0, 2
 * 2 -> 1
 * Means that node (A,B) points to the node (A,D) for exampel
 */
struct TreeDecomposition
{
   matrix subset;
   matrix tree;
};


void print_graph( Graph );
void print_TD ( TreeDecomposition );
TreeDecomposition Permuation_to_tree_decomposition( Graph, unsigned );



int main()
{
   Graph G;
   
   std::set<unsigned> edges;

   /*
    * Create thre four vertexed (0-3). 
    * Index 0 in G.matrix in vertex 1. G.matrix.at( 0 ).at( j ), where j < G.matrix.size() 
    * will return edge j for vertex 0. Since the edges are stored in a set, there can be
    * no parallel edges and they are sorted by numbers
    */

   //vertex 0
   edges.insert( 1 );
   edges.insert( 2 );
   G.vertex.push_back( edges );

   //vertex 1
   edges.clear();
   edges.insert( 0 );
   edges.insert( 2 );
   edges.insert( 3 );
   G.vertex.push_back( edges );

   //vertex 2
   edges.clear();
   edges.insert( 0 );
   edges.insert( 1 );
   G.vertex.push_back( edges );

   //vertex 3
   edges.clear();
   edges.insert( 1 );
   G.vertex.push_back( edges );

   print_graph( G );

   TreeDecomposition temp  = Permuation_to_tree_decomposition( G, 0 );
   print_TD( temp );


   return 0;
}



Graph eliminating( const Graph G_in, unsigned v_1 )
{
   /*
    * The node v_1 and all edges that points to v_1 are not removed
    * Instead of removing them which will vilance the structure of the graph, we simply ignore all edged that has a lower value then v_1
    * Which means, this function just edges
    */

   Graph G = G_in;
   for( auto j = v_1 + 1; j < G.vertex.size(); ++j )
   {
      for( auto& edge : G.vertex.at( v_1 ) ) // for all edged in v_1
      {
         G.vertex.at(j).insert( edge );
      }
   }

   return G;
}


TreeDecomposition Permuation_to_tree_decomposition( Graph G, unsigned v_1 )
{
   if( G.vertex.size() - v_1 == 1 )
   {
      TreeDecomposition T;
      std::set<unsigned> s{ v_1 };
      std::set<unsigned> t{  };

      T.subset.push_back( s );
      T.tree.push_back( t );

      return T;
   }

   Graph G_ = eliminating( G, v_1 );
   TreeDecomposition T = Permuation_to_tree_decomposition( G_, v_1 + 1);

   //find v_j 
   unsigned v_j;   
   for( auto& edge : G.vertex.at( v_1 ) )
   {
      if( edge > v_1 ) //the neighbours are sorted
      {
         v_j = edge;
          break;
      }
   }
   
   //Ng(v_1)
   std::set<unsigned> temp;
   for( auto edge : G.vertex.at( v_1 ) )
   {
      //All edges smaller shall be ignored because they should been removed in earlier steps
      if( edge > v_1  )
      {
         temp.insert( edge );
      }
   }
   //Ng[v_1]
   temp.insert( v_1 );
   T.subset.push_back( temp );

   
   //Add edges X_V_1, X_V_J
   T.tree.push_back( std::set<unsigned> {} );
   unsigned new_edge;

   //From X_v_1
   new_edge = G.vertex.size() - v_j - 1;
   T.tree.at( T.tree.size() - 1 ).insert( new_edge );

   //To X_v_1
   new_edge = T.tree.size() - 1;
   T.tree.at( G.vertex.size() - v_j - 1 ).insert( new_edge );

   
   return T;
}

void print_graph( Graph G )
{
   std::cout << "*******GRAPH*******\n";
   matrix list = G.vertex; 
   for( auto i = 0; i < list.size(); ++i)
   {
      auto v = list.at(i);
      std::cout << i << " -> ";
      for( auto& e : v )
      {
         std::cout << e << ", ";
      }
      std::cout << "\n";
   } 
   std::cout << "*******************\n";
}

void print_TD( TreeDecomposition TD )
{
   std::cout << "*******TreeDecomposition*******\n";

   /*
   for( auto i = 0; i < TD.subset.size(); ++i)
   {
      auto v = TD.subset.at(i);
      for( auto& e : v )
      {
         std::cout << e << " ";
      }
      std::cout << "\n";
   } 
   */

  matrix list = TD.tree; 

  //print a vertex in the tree
  for( auto i = 0; i < list.size(); ++i)
  {
     std::cout << "\n( ";
     auto v = TD.subset.at(i);
     for( auto& e : v )
     {
            std::cout << e << " ";
     } 
     std::cout << " ) -> ";

     //print the vertexes edges
     v = TD.tree.at(i); //this is the vertex 
     for(auto it = v.begin(); it != v.end(); ++it )
     {
        
        std::cout << "( ";
        for( auto& e : TD.subset.at( *it ) )
        {
           std::cout << e << " ";
        }
       //std::cout << *it << " ";
       std::cout << " ), ";
     }
     std::cout << "\n";
  }
  std::cout << "*******************************\n";
}


