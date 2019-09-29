#include<iostream>
using namespace std;

int lastIndex(int a[],int i,int n,int key)
{
	if(i==n)
	{
		return -1;
	}

	if(a[i]==key)
	{
		int pheleWalaIndex=i;
		int lastWalaIndex=lastIndex(a,i+1,n,key);
		if(pheleWalaIndex>lastWalaIndex)
		{
			return pheleWalaIndex;
		}
		else
		{
			return lastWalaIndex;
		}
	}

	return lastIndex(a,i+1,n,key);
}

int firstIndex(int a[],int i,int n,int key)
{
	if(i==n)
	{
		return -1;
	}

	if(a[i]==key)
	{
		return i;
	}

	return firstIndex(a,i+1,n,key);
}

bool isPresent(int a[],int i,int n,int key)
{
	if(i==n)
	{
		return false;
	}

	if(a[i]==key)
	{
		return true;
	}
	
	return isPresent(a,i+1,n,key);
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;

	if(isPresent(a,0,n,key))
	{
		cout<<"present"<<endl;
	}
	else
	{
		cout<<"Not present"<<endl;
	}

	cout<<firstIndex(a,0,n,key)<<endl;
	cout<<lastIndex(a,0,n,key)<<endl;
	return 0;
}















