#include<iostream>
#include<map>
#include<list>
#include<queue>

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

   void bfs(T src)
   {
   	  queue<T>q;
   	  map<T,bool>visited;

   	  q.push(src);
   	  visited[src]=true;

   	  while(!q.empty())
   	  {
   	  	T top=q.front();
   	  	q.pop();

   	  	cout<<top<<" ";

   	  	for(auto neighbor:adjlist[top])
   	  	{
   	  		if(!visited[neighbor])
   	  		{
   	  			q.push(neighbor);
   	  			visited[neighbor]=true;
   	  		}
   	  	}
   	  }
   }


   void SSSP(T src,T dest)
   {
   		map<T,int>distance;
   		queue<T>q;
   		map<T,T>parent;

   		for(auto node:adjlist)
   		{
   			distance[node.first]=INT_MAX;
   		}
   		distance[src]=0;
   		q.push(src);
   		parent[src]=src; //parent[src]=-1;

   		while(!q.empty())
   		{
   			T top=q.front();
   			q.pop();

   			for(auto neighbor:adjlist[top])
   			{
   				if(distance[neighbor]==INT_MAX)
   				{
   					parent[neighbor]=top;
   					distance[neighbor]=distance[top]+1;
   					q.push(neighbor);
   				}
   			}
   		}

   		for(auto d:distance)
   		{
   			cout<<d.first<<" "<<d.second<<endl;
   		}

   		T temp=dest;
   		while(temp!=src)
   		{
   			cout<<temp<<"<--";
   			temp=parent[temp];
   		}
   		cout<<src;
   }

   void dfsHelper(T src,map<T,bool>&visited)
   {
   		cout<<src<<" ";
   		visited[src]=true;

   		for(auto neighbor:adjlist[src])
   		{
   			if(!visited[neighbor])
   			{
   				dfsHelper(neighbor,visited);
   			}
   		}
   }

   void dfs(T src)
   {
   		map<T,bool>visited;
   		dfsHelper(src,visited);
   		int componant=1;

   		for(auto node:adjlist)
   		{
   			if(!visited[node.first])
   			{
   				dfsHelper(node.first,visited);
   				componant++;
   			}
   		}

   		cout<<"No of componants are "<<componant<<endl;
   }


};

int main()
{
	Graph<int>g;

	g.addEdge(0,4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(6,7);


	// Graph<string>g;
	// g.addEdge("modi","yogi",false);
	// g.addEdge("modi","trump",false);
	// g.addEdge("prabhu","modi",false);
	// g.addEdge("trump","modi",false);
 //    g.addEdge("yogi","modi",false);
 //    g.addEdge("yogi","prabhu",false);
 //    g.addEdge("putin","trump",false);
 //    g.addEdge("putin","modi",false);
 //    g.addEdge("putin","pope",false);

	// g.print();
	// g.bfs(0);

	// g.SSSP(0,2);
	g.dfs(0);

	return 0;
}









