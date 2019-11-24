#include<iostream>
#include<map>
#include<list>

using namespace std;

template<typename T>
class Graph
{
public:
   map<T,list<T> >adjlist;

   void addEdge(T u,T v,bool bidir=true)
   {
   	 adjlist[u].push_back(v);
   	 if(bidir)
   	 {
   	 	adjlist[v].push_back(u);
   	 }
   }

   void print()
   {
   	  for(auto node:adjlist)
   	  {
   	  	 cout<<node.first<<"-->";

   	  	 for(auto neighbor:node.second)
   	  	 {
   	  	 	cout<<neighbor<<" ";
   	  	 }
   	  	 cout<<endl;
   	  }
   }

};

int main()
{
	// Graph<int>g;

	// g.addEdge(0,4);
	// g.addEdge(0,1);
	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(1,4);
	// g.addEdge(2,3);
	// g.addEdge(3,4);


	Graph<string>g;
	g.addEdge("modi","yogi",false);
	g.addEdge("modi","trump",false);
	g.addEdge("prabhu","modi",false);
	g.addEdge("trump","modi",false);
    g.addEdge("yogi","modi",false);
    g.addEdge("yogi","prabhu",false);
    g.addEdge("putin","trump",false);
    g.addEdge("putin","modi",false);
    g.addEdge("putin","pope",false);
    
	g.print();

	return 0;
}









