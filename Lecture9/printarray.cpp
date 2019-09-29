#include<iostream>
using namespace std;

void printArray(int *a,int n)
{
	if(n==0)
	{
		return;
	}

	// cout<<a[0]<<" ";
	printArray(a+1,n-1);
	cout<<a[0]<<" ";
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
	printArray(a,n);
	return 0;
}