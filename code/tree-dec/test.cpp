#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using matrix = std::vector< std::vector<int> >;


//The (directed ) Graph is implemented as a adjacency list
struct Graph
{
   matrix vertex;
};

/*
 * Each row in the matrix "subset" in the class TreeDecomposition represent a node in the tree
 * If the subset looks like:
 * 0 ->A,B
 * 1 ->A,D
 * 2 ->C,D
 * Means for example that we have three nodes in the graph were N_0 is (A,B)
 *
 * The matrix "tree" in the class TreeDecomposition stores the edges for the tree
 * The matrix tree looks like
 * 0 -> 1
 * 1 -> 0, 2
 * 2 -> 1
 * Means that node (A,B) points to the node (A,D)
 */
struct TreeDecomposition
{
   matrix subset;
   matrix tree;
};


void print_graph( Graph );
void print_TD ( TreeDecomposition );
TreeDecomposition Permuation_to_tree_decomposition( Graph, int );



int main()
{
   Graph G;
   
   std::vector<int> edges;

   /*
    * We create a Graph G with three vertexex  (0-3). 
    * Index 0 in G.matrix is vertex 1. G.matrix.at( 0 ).at( j ), where j < G.matrix.size() 
    * will return edge j for vertex 0. All pararell edges will be removed in the TreeDecompostion-function
    */

   //vertex 0
   edges.push_back( 1 );
   edges.push_back( 2 );
   G.vertex.push_back( edges );

   //vertex 1
   edges.clear();
   edges.push_back( 0 );
   edges.push_back( 2 );
   edges.push_back( 3 );
   G.vertex.push_back( edges );

   //vertex 2
   edges.clear();
   edges.push_back( 0 );
   edges.push_back( 1 );
   G.vertex.push_back( edges );

   //vertex 3
   edges.clear();
   edges.push_back( 1 );
   G.vertex.push_back( edges );

   print_graph( G );

   TreeDecomposition TD  = Permuation_to_tree_decomposition( G, 0 );
   print_TD( TD );


   return 0;
}



Graph eliminating( const Graph G_in, int v_1 )
{
   /*
    * The node v_1 and all edges that points to v_1 will not removed,
    * Instead of removing them which will vilance the structure of the graph, we simply ignore all edged that has a lower value then v_1 later
    * Before we return, we make sure that there are no parallel edges
    */

   Graph G = G_in;
   for( unsigned long i = v_1 + 1; i < G.vertex.size(); ++i ) // for all vertex > v_1
   {
      for( auto& edge : G.vertex.at( v_1 ) ) // for all edged in v_1
      {
         G.vertex.at(i).push_back( edge );
      }
   }

   for( unsigned long i = v_1 + 1; i < G.vertex.size(); ++i )
   {
      std::vector<int>& vec = G.vertex.at(i);
      sort( vec.begin(), vec.end() );
      vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
   }
      return G;
}


TreeDecomposition Permuation_to_tree_decomposition( Graph G, int v_1 )
{
   if( G.vertex.size() - v_1 == 1 )
   {
      TreeDecomposition TD; 
      
      TD.subset.push_back( { v_1 } );
      TD.tree.push_back( {} );

      return TD;
   }

   Graph G_ = eliminating( G, v_1 );
   TreeDecomposition TD = Permuation_to_tree_decomposition( G_, v_1 + 1);

   //find v_j AND Ng(v_1) 
   int v_j = std::numeric_limits<int>::max();  
   std::vector<int> Ng_v_1;
   for( auto& edge : G.vertex.at( v_1 ) )
   {
      //All edges smaller shall be ignored because they should been removed in earlier steps
      if( edge > v_1  )
      {
         //Add edge to Ng(v_1)
         Ng_v_1.push_back( edge );

         //Find v_j
         if( v_j > edge )
         {
            v_j = edge;
         }
      }
   }
   
   //Ng[v_1]
   Ng_v_1.push_back( v_1 );


   //Add Ng[v_1] as a node
   TD.subset.push_back( Ng_v_1 );

   
   //Add edges X_V_1, X_V_J
   TD.tree.push_back( {} );
   int new_edge;

   //From X_v_1
   new_edge = G.vertex.size() - v_j - 1;
   TD.tree.at( TD.tree.size() - 1 ).push_back( new_edge );

   //To X_v_1
   new_edge = TD.tree.size() - 1;
   TD.tree.at( G.vertex.size() - v_j - 1 ).push_back( new_edge );

   
   return TD;
}

void print_graph( Graph G )
{
   std::cout << "*******GRAPH*******\n";
   matrix list = G.vertex; 
   for( unsigned long i = 0; i < list.size(); ++i)
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

   matrix list = TD.tree; 
  //print a vertex in the tree
  for( unsigned long i = 0; i < list.size(); ++i)
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


