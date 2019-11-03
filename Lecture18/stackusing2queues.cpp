#include<iostream>
#include<queue>
using namespace std;

class Stack
{
public:
	queue<int>q1,q2;
	int curr_size;

	Stack()
	{
		curr_size=0;
	}

	void push(int d)
	{
		q1.push(d);
		curr_size++;
	}

	void pop()
	{
		if(q1.empty())
		{
			return;
		}

		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		curr_size--;

		queue<int>q;
		q=q1;
		q1=q2;
		q2=q;
	}


	int top()
	{
		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		int top=q1.front();
		q2.push(top);
		q1.pop();

		queue<int>q;
		q=q1;
		q1=q2;
		q2=q;

		return top;
	}
	int size()
	{
		return curr_size;
	}

	bool empty()
	{
		return curr_size==0;
	}


};


int main()
{

	Stack s;
	s.push(100);
	s.push(250);

	cout<<s.top()<<endl; //250
	s.pop();
	cout<<s.top()<<endl; //100
	return 0;
}
















