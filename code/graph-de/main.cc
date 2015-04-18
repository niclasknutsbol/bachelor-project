#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

unsigned maximal_matching( Graph G );
unsigned number_of_green_nodes( Graph G );
vector<vector<unsigned> contraction( G, M );
int decompositions( Graph G, const unsigned k )
int main()
{








   return 0;
}



unsigned number_of_green_nodes( Graph G )
{
   //Create a vector color of size V and set all to 0
   //If a vertex is a lower degree set it to color 1
   auto V = G.size();
   std::vector<unsigned> color( V );

   //TODO THE GRAPH SHOULD PROBALY BE TRANSFORMED BEFORE THE FOR-LOOP
   
   for( unsigned i = 0; i < V; ++i )
   {
      if( v.size() <  max( pow(k,2) + 4*k + 4, floor( 2*k/c_1 ) ) ) 
      {
         color.at(i) = 1;
      }
   }

   //if a vertex is a neighbour with another low degree, set it to 2
   for( unsigned i = 0; i < V; ++i )
   {
      if( color.at(i) == 1 )
      { 
         for( unsigned j = 0; i < V; ++j )
         {
            if( j != i and color.at( G.at(i).G.at(j) ) == 1 )
            {
               color.at(i) = 2;
            }
         }
      }
   }

   //Count how many index in color that are = 2
   auto sum = 0;
   for( auto v : color )
   {
      if( v == 2 )
      {
         sum = sum + v;
      }
   }

   return sum;
}

unsigned maximal_matching( Graph G )
{
   auto V = G.size();
   vector< vector<unsigned> > M;


   for( unsigned i = 0; V < i; ++i )
   {
      if( M.at(i).size() == 0 )
      {
         for( insigned j = 0; Graph.at(i).size(); ++j )
         {
            if( color.at(j) == false )
            {
               color.at(i).at(j).push_back( 1 );
            }
         }
      }
   }
   return M;
}

vector<vector<unsigned> contraction( G, M )
{


}


int decompositions( Graph G, const unsigned k )
{
   auto V = G.size();
   auto E = 0;
   for( auto v : Graph )
   {
      E = E + v.size();
   }

   if( E > k * V - k* ( k + 1 )/2 )
   {
      return -1;
   }

   if( number_of_green_nodes( G ) >= V / (4 * pow(k,2) + 12 * k + 16)  )
   {
      auto M = maxmimal_matching( G );
      G_ = contracting( G, M );

      auto result = decompisitions( G, k );

      if( result.k > k )
      {
         return result;
      }

      //2.8
    
      //2.10

   } //More green...
   else
   {
      
   }
}
