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

   		// for(auto d:distance)
   		// {
   		// 	cout<<d.first<<" "<<d.second<<endl;
   		// }

   		T temp=dest;
   		while(temp!=src)
   		{
   			cout<<temp<<"<--";
   			temp=parent[temp];
   		}
   		cout<<src;
   }


};

int main()
{
	Graph<int>g;

   int board[50]={0};  
   board[2] = 13;
   board[5] = 2;
   board[9] = 18;
   board[18] = 11;
   board[17] = -13;  
   board[20] = -14;
   board[24] = -8;
   board[25] = -10;
   board[32] = -2;
   board[34] = -22;


   for(int u=0;u<=36;u++)
   {
      for(int dice=1;dice<=6;dice++)
      {
         int v=u+dice+board[u+dice];
         g.addEdge(u,v,false);
      }
   }

	// g.SSSP(0,36);
	return 0;
}









