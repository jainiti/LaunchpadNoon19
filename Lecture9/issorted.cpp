#include<iostream>
using namespace std;

bool isSorted(int *a,int n)
{
	if(n==1 || n==0)
	{
		return true;
	}

	bool kyaAageSortedMila=isSorted(a+1,n-1);
	if(a[0]<=a[1] && kyaAageSortedMila)
	{
		return true;
	}
	return false;
}


bool isSorted1(int a[],int i,int n)
{

	if(i==n-1)
	{
		return true;
	}

	bool kyaAageSortedMila=isSorted1(a,i+1,n);
	if(a[i]<=a[i+1]&& kyaAageSortedMila)
	{
		return true;
	}
	return false;
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

	if(isSorted(a,n))
	{
		cout<<"sorted"<<endl;
	}
	else
	{
		cout<<"unsorted"<<endl;
	}
	return 0;
}