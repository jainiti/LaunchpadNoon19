#include<iostream>
#include<queue>
using namespace std;

void print(priority_queue<int,vector<int>,greater<int> >pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

int main()
{
	int k;
	cin>>k;

	priority_queue<int,vector<int>,greater<int> >pq;
	int count=0;
	while(1)
	{
		int input;
		cin>>input;

		if(input==-1)
		{
			print(pq);
		}

		else if(count<k)
		{
			pq.push(input);
			count++;
		}

		else if(pq.top()<input)
		{
			pq.pop();
			pq.push(input);
		}

	}
	return 0;
}













