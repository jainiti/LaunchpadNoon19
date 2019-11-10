#include<iostream>
#include<vector>
using namespace std;


class minHeap
{

	void heapify(int index)
	{
		int leftchild=2*index;
		int rightchild=2*index+1;

		int ans=index;
		if(leftchild<v.size()&&v[leftchild]<v[ans])
		{
			ans=leftchild;
		}

		if(rightchild<v.size()&&v[rightchild]<v[ans])
		{
			ans=rightchild;
		}

		if(ans!=index)
		{
			swap(v[index],v[ans]);
			heapify(ans);
		}
	}

public:
	vector<int>v;

	minHeap()
	{
		v.push_back(-1);
	}

	void push(int data)
	{
		v.push_back(data);
		int child=v.size()-1;
		int parent=child/2;

		while(parent>0 && v[parent]>v[child])
		{
			swap(v[parent],v[child]);
			child=parent;
			parent=parent/2;
		}
	}

	void pop()
	{
		swap(v[1],v[v.size()-1]);
		v.pop_back();

		heapify(1);
	}

	int top()
	{
		return v[1];
	}

	bool empty()
	{
		return v.size()==1;
	}
};




int main()
{

	minHeap m;
	m.push(5);
	m.push(62);
	m.push(21);
	m.push(32);
	m.push(0);


	while(!m.empty())
	{
		cout<<m.top()<<" ";
		m.pop();
	}
	return 0;
}
















