#include<iostream>
#include<list>
#include<map>
#include<set>

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

	void SSSP(T src)
	{
		map<T,int>distance;
		set<pair<int,T> >s;

		for(auto node:adjlist)
		{
			distance[node.first]=INT_MAX;
		}
		distance[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			auto p=*(s.begin());
			int parentDistance=p.first;
			T parent=p.second;
			s.erase(s.begin());

			for(auto child:adjlist[parent])
			{
				if(distance[child.first]>distance[parent]+child.second)
				{
					auto f=s.find(make_pair(distance[child.first],child.first));
					if(f!=s.end())
					{
						s.erase(f);
					}

					distance[child.first]=parentDistance+child.second;
					s.insert(make_pair(distance[child.first],child.first));
				}
			}
		}


		for(auto d:distance)
		{
			cout<<d.first<<" "<<d.second<<endl;
		}
	}
};


int main()
{
	Graph<int>g;

	// g.addEdge(0,1,2);
	// g.addEdge(0,4,7);
	// g.addEdge(1,3,6);
	// g.addEdge(1,4,5);
	// g.addEdge(2,4,4);
	// g.addEdge(2,3,3);

	g.addEdge(1,2,10);
	g.addEdge(1,3,5);
	g.addEdge(1,4,50);
	g.addEdge(2,4,15);
	g.addEdge(2,5,20);
	g.addEdge(3,4,25);
	g.addEdge(4,5,40);

	// g.print();
	g.SSSP(1);

	return 0;
}





