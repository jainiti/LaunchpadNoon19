#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int,vector<int> >pq;
	pq.push(67);
	pq.push(32);
	pq.push(-1);
	pq.push(45);

	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}

	priority_queue<int,vector<int>,greater<int> >pq1;
	pq1.push(67);
	pq1.push(32);
	pq1.push(-1);
	pq1.push(45);

	while(!pq1.empty())
	{
		cout<<pq1.top()<<" ";
		pq1.pop();
	}
	return 0;
}