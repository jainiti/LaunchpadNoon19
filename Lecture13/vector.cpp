#include<iostream>
using namespace std;

class Vector
{
public:
	int *arr;
	int cs;
	int ms;

	Vector(int n=1)
	{
		cs=0;
		ms=n;
		arr=new int[n];
	}

	void push_back(int data)
	{
		if(cs==ms)
		{
			int *oldarr=arr;
			arr=new int[2*ms];
			for(int i=0;i<cs;i++)
			{
				arr[i]=oldarr[i];
			}
			ms=2*ms;
			delete []oldarr;
		}

		arr[cs]=data;
		cs++;
	}

	void pop_back()
	{
		if(cs>0)
		{
			cs--;
		}
	}

	int size()
	{
		return cs;
	}

	int capacity()
	{
		return ms;
	}

	bool empty()
	{
		return cs==0;
	}

	int operator[](int i)
	{
		return arr[i];
	}

};

int main()
{
	Vector v(2);
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}

	cout<<endl;
	v.pop_back();

	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}









