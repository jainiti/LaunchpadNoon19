#include<iostream>
using namespace std;

int main()
{
	int a[]={45,78,90,32,1,0};
	int n=sizeof(a)/sizeof(int);

	//bubble sort
	for(int step=0;step<n-1;step++)
	{
		for(int i=0;i<n-step-1;i++)
		{
			if(a[i+1]<a[i])
			{
				swap(a[i],a[i+1]);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
