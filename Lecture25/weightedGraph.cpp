#include<iostream>
#include<list>
#include<map>

using namespace std;

template<typename T>
class Graph
{
public:

	map<T,list<pair<T,int> > >adjlist;

	void addEdge(T u,T v,int weight,bool bidir=true)
	{
		adjlist[u].push_back(make_pair(v,weight));
		if(bidir)
		{
			adjlist[v].push_back(make_pair(u,weight));
		}
	}

	void print()
	{
		for(auto node:adjlist)
		{
			cout<<node.first<<"-->";
			for(auto neighbor:node.second)
			{
				cout<<"("<<neighbor.first<<" "<<neighbor.second<<") ";
			}
			cout<<endl;
		}
	}
};


int main()
{
	Graph<int>g;

	g.addEdge(0,1,2);
	g.addEdge(0,4,7);
	g.addEdge(1,3,6);
	g.addEdge(1,4,5);
	g.addEdge(2,4,4);
	g.addEdge(2,3,3);

	g.print();
	return 0;
}





